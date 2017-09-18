// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package pem

import (
	"bytes"
	"io/ioutil"
	"reflect"
	"strings"
	"testing"
	"testing/quick"
)

type GetLineTest struct {
	in, out1, out2 string
}

var getLineTests = []GetLineTest{
	{"abc", "abc", ""},
	{"abc\r", "abc\r", ""},
	{"abc\n", "abc", ""},
	{"abc\r\n", "abc", ""},
	{"abc\nd", "abc", "d"},
	{"abc\r\nd", "abc", "d"},
	{"\nabc", "", "abc"},
	{"\r\nabc", "", "abc"},
}

func TestGetLine(t *testing.T) {
	for i, test := range getLineTests {
		x, y := getLine([]byte(test.in))
		if string(x) != test.out1 || string(y) != test.out2 {
			t.Errorf("#%d got:%+v,%+v want:%s,%s", i, x, y, test.out1, test.out2)
		}
	}
}

func TestDecode(t *testing.T) {
	result, remainder := Decode([]byte(pemData))
	if !reflect.DeepEqual(result, certificate) {
		t.Errorf("#0 got:%#v want:%#v", result, certificate)
	}
	result, remainder = Decode(remainder)
	if !reflect.DeepEqual(result, privateKey) {
		t.Errorf("#1 got:%#v want:%#v", result, privateKey)
	}

	isEmpty := func(block *Block) bool {
		return block != nil && block.Type == "EMPTY" && len(block.Headers) == 0 && len(block.Bytes) == 0
	}
	result, remainder = Decode(remainder)
	if !isEmpty(result) {
		t.Errorf("#2 should be empty but got:%#v", result)
	}
	result, remainder = Decode(remainder)
	if !isEmpty(result) {
		t.Errorf("#3 should be empty but got:%#v", result)
	}
	result, remainder = Decode(remainder)
	if !isEmpty(result) {
		t.Errorf("#4 should be empty but got:%#v", result)
	}

	result, remainder = Decode(remainder)
	if result == nil || result.Type != "HEADERS" || len(result.Headers) != 1 {
		t.Errorf("#5 expected single header block but got :%v", result)
	}

	if len(remainder) != 0 {
		t.Errorf("expected nothing remaining of pemData, but found %s", string(remainder))
	}

	result, _ = Decode([]byte(pemPrivateKey2))
	if !reflect.DeepEqual(result, privateKey2) {
		t.Errorf("#2 got:%#v want:%#v", result, privateKey2)
	}
}

const pemTooFewEndingDashes = `
-----BEGIN FOO-----
dGVzdA==
-----END FOO----`

const pemTooManyEndingDashes = `
-----BEGIN FOO-----
dGVzdA==
-----END FOO------`

const pemTrailingNonWhitespace = `
-----BEGIN FOO-----
dGVzdA==
-----END FOO----- .`

const pemWrongEndingType = `
-----BEGIN FOO-----
dGVzdA==
-----END BAR-----`

const pemMissingEndingSpace = `
-----BEGIN FOO-----
dGVzdA==
-----ENDBAR-----`

var badPEMTests = []struct {
	name  string
	input string
}{
	{
		"too few trailing dashes",
		pemTooFewEndingDashes,
	},
	{
		"too many trailing dashes",
		pemTooManyEndingDashes,
	},
	{
		"trailing non-whitespace",
		pemTrailingNonWhitespace,
	},
	{
		"incorrect ending type",
		pemWrongEndingType,
	},
	{
		"missing ending space",
		pemMissingEndingSpace,
	},
}

func TestBadDecode(t *testing.T) {
	for _, test := range badPEMTests {
		result, _ := Decode([]byte(test.input))
		if result != nil {
			t.Errorf("unexpected success while parsing %q", test.name)
		}
	}
}

func TestEncode(t *testing.T) {
	r := EncodeToMemory(privateKey2)
	if string(r) != pemPrivateKey2 {
		t.Errorf("got:%s want:%s", r, pemPrivateKey2)
	}
}

type lineBreakerTest struct {
	in, out string
}

const sixtyFourCharString = "0123456789012345678901234567890123456789012345678901234567890123"

var lineBreakerTests = []lineBreakerTest{
	{"", ""},
	{"a", "a\n"},
	{"ab", "ab\n"},
	{sixtyFourCharString, sixtyFourCharString + "\n"},
	{sixtyFourCharString + "X", sixtyFourCharString + "\nX\n"},
	{sixtyFourCharString + sixtyFourCharString, sixtyFourCharString + "\n" + sixtyFourCharString + "\n"},
}

func TestLineBreaker(t *testing.T) {
	for i, test := range lineBreakerTests {
		buf := new(bytes.Buffer)
		var breaker lineBreaker
		breaker.out = buf
		_, err := breaker.Write([]byte(test.in))
		if err != nil {
			t.Errorf("#%d: error from Write: %s", i, err)
			continue
		}
		err = breaker.Close()
		if err != nil {
			t.Errorf("#%d: error from Close: %s", i, err)
			continue
		}

		if string(buf.Bytes()) != test.out {
			t.Errorf("#%d: got:%s want:%s", i, string(buf.Bytes()), test.out)
		}
	}

	for i, test := range lineBreakerTests {
		buf := new(bytes.Buffer)
		var breaker lineBreaker
		breaker.out = buf

		for i := 0; i < len(test.in); i++ {
			_, err := breaker.Write([]byte(test.in[i : i+1]))
			if err != nil {
				t.Errorf("#%d: error from Write (byte by byte): %s", i, err)
				continue
			}
		}
		err := breaker.Close()
		if err != nil {
			t.Errorf("#%d: error from Close (byte by byte): %s", i, err)
			continue
		}

		if string(buf.Bytes()) != test.out {
			t.Errorf("#%d: (byte by byte) got:%s want:%s", i, string(buf.Bytes()), test.out)
		}
	}
}

func TestFuzz(t *testing.T) {
	// PEM is a text-based format. Assume header fields with leading/trailing spaces
	// or embedded newlines will not round trip correctly and don't need to be tested.
	isBad := func(s string) bool {
		return strings.ContainsAny(s, "\r\n") || strings.TrimSpace(s) != s
	}

	testRoundtrip := func(block Block) bool {
		if isBad(block.Type) {
			return true
		}
		for key, val := range block.Headers {
			// Reject bad key/val.
			// Also, keys with colons cannot be encoded, because : is the key: val separator.
			if isBad(key) || isBad(val) || strings.Contains(key, ":") {
				return true
			}
		}

		var buf bytes.Buffer
		if err := Encode(&buf, &block); err != nil {
			t.Errorf("Encode of %#v resulted in error: %s", &block, err)
			return false
		}
		decoded, rest := Decode(buf.Bytes())
		if block.Headers == nil {
			// Encoder supports nil Headers but decoder returns initialized.
			block.Headers = make(map[string]string)
		}
		if block.Bytes == nil {
			// Encoder supports nil Bytes but decoder returns initialized.
			block.Bytes = make([]byte, 0)
		}
		if !reflect.DeepEqual(decoded, &block) {
			t.Errorf("Encode of %#v decoded as %#v", &block, decoded)
			return false
		}
		if len(rest) != 0 {
			t.Errorf("Encode of %#v decoded correctly, but with %x left over", block, rest)
			return false
		}
		return true
	}

	// Explicitly test the empty block.
	if !testRoundtrip(Block{
		Type:    "EMPTY",
		Headers: make(map[string]string),
		Bytes:   []byte{},
	}) {
		return
	}

	quick.Check(testRoundtrip, nil)
}

func BenchmarkEncode(b *testing.B) {
	data := &Block{Bytes: make([]byte, 65536)}
	b.SetBytes(int64(len(data.Bytes)))
	for i := 0; i < b.N; i++ {
		Encode(ioutil.Discard, data)
	}
}

func BenchmarkDecode(b *testing.B) {
	block := &Block{Bytes: make([]byte, 65536)}
	data := EncodeToMemory(block)
	b.SetBytes(int64(len(data)))
	b.ResetTimer()
	for i := 0; i < b.N; i++ {
		Decode(data)
	}
}

var pemData = `verify return:0
-----BEGIN CERTIFICATE-----
sdlfkjskldfj
  -----BEGIN CERTIFICATE-----
---
Certificate chain
 0 s:/C=AU/ST=Somewhere/L=Someplace/O=Foo Bar/CN=foo.example.com
   i:/C=ZA/O=CA Inc./CN=CA Inc
-----BEGIN CERTIFICATE-----
testing
-----BEGIN CERTIFICATE-----
-----BEGIN CERTIFICATE----- 
MIID6TCCA1ICAQEwDQYJKoZIhvcNAQEFBQAwgYsxCzAJBgNVBAYTAlVTMRMwEQYD
VQQIEwpDYWxpZm9ybmlhMRYwFAYDVQQHEw1TYW4gRnJhbmNpc2NvMRQwEgYDVQQK
EwtHb29nbGUgSW5jLjEMMAoGA1UECxMDRW5nMQwwCgYDVQQDEwNhZ2wxHTAbBgkq 
hkiG9w0BCQEWDmFnbEBnb29nbGUuY29tMB4XDTA5MDkwOTIyMDU0M1oXDTEwMDkw  
OTIyMDU0M1owajELMAkGA1UEBhMCQVUxEzARBgNVBAgTClNvbWUtU3RhdGUxITAf  	  
BgNVBAoTGEludGVybmV0IFdpZGdpdHMgUHR5IEx0ZDEjMCEGA1UEAxMaZXVyb3Bh		  
LnNmby5jb3JwLmdvb2dsZS5jb20wggIiMA0GCSqGSIb3DQEBAQUAA4ICDwAwggIK
AoICAQC6pgYt7/EibBDumASF+S0qvqdL/f+nouJw2T1Qc8GmXF/iiUcrsgzh/Fd8
pDhz/T96Qg9IyR4ztuc2MXrmPra+zAuSf5bevFReSqvpIt8Duv0HbDbcqs/XKPfB
uMDe+of7a9GCywvAZ4ZUJcp0thqD9fKTTjUWOBzHY1uNE4RitrhmJCrbBGXbJ249
bvgmb7jgdInH2PU7PT55hujvOoIsQW2osXBFRur4pF1wmVh4W4lTLD6pjfIMUcML
ICHEXEN73PDic8KS3EtNYCwoIld+tpIBjE1QOb1KOyuJBNW6Esw9ALZn7stWdYcE
qAwvv20egN2tEXqj7Q4/1ccyPZc3PQgC3FJ8Be2mtllM+80qf4dAaQ/fWvCtOrQ5
pnfe9juQvCo8Y0VGlFcrSys/MzSg9LJ/24jZVgzQved/Qupsp89wVidwIzjt+WdS
fyWfH0/v1aQLvu5cMYuW//C0W2nlYziL5blETntM8My2ybNARy3ICHxCBv2RNtPI
WQVm+E9/W5rwh2IJR4DHn2LHwUVmT/hHNTdBLl5Uhwr4Wc7JhE7AVqb14pVNz1lr
5jxsp//ncIwftb7mZQ3DF03Yna+jJhpzx8CQoeLT6aQCHyzmH68MrHHT4MALPyUs
Pomjn71GNTtDeWAXibjCgdL6iHACCF6Htbl0zGlG0OAK+bdn0QIDAQABMA0GCSqG
SIb3DQEBBQUAA4GBAOKnQDtqBV24vVqvesL5dnmyFpFPXBn3WdFfwD6DzEb21UVG
5krmJiu+ViipORJPGMkgoL6BjU21XI95VQbun5P8vvg8Z+FnFsvRFY3e1CCzAVQY
ZsUkLw2I7zI/dNlWdB8Xp7v+3w9sX5N3J/WuJ1KOO5m26kRlHQo7EzT3974g
-----END CERTIFICATE-----   
 1 s:/C=ZA/O=Ca Inc./CN=CA Inc

-----BEGIN RSA PRIVATE KEY-----   	
Proc-Type: 4,ENCRYPTED	  
DEK-Info: DES-EDE3-CBC,80C7C7A09690757A  	
  	
eQp5ZkH6CyHBz7BZfUPxyLCCmftsBJ7HlqGb8Ld21cSwnzWZ4/SIlhyrUtsfw7VR
2TTwA+odo9ex7GdxOTaH8oZFumIRoiEjHsk8U7Bhntp+ekkPP79xunnN7hb7hkhr   
yGDQZgA7s2cQHQ71v3gwT2BACAft26jCjbM1wgNzBnJ8M0Rzn68YWqaPtdBu8qb/
zVR5JB1mnqvTSbFsfF5yMc6o2WQ9jJCl6KypnMl+BpL+dlvdjYVK4l9lYsB1Hs3d
+zDBbWxos818zzhS8/y6eIfiSG27cqrbhURbmgiSfDXjncK4m/pLcQ7mmBL6mFOr
3Pj4jepzgOiFRL6MKE//h62fZvI1ErYr8VunHEykgKNhChDvb1RO6LEfqKBu+Ivw
TB6fBhW3TCLMnVPYVoYwA+fHNTmZZm8BEonlIMfI+KktjWUg4Oia+NI6vKcPpFox
hSnlGgCtvfEaq5/H4kHJp95eOpnFsLviw2seHNkz/LxJMRP1X428+DpYW/QD/0JU
tJSuC/q9FUHL6RI3u/Asrv8pCb4+D7i1jW/AMIdJTtycOGsbPxQA7yHMWujHmeb1
BTiHcL3s3KrJu1vDVrshvxfnz71KTeNnZH8UbOqT5i7fPGyXtY1XJddcbI/Q6tXf
wHFsZc20TzSdsVLBtwksUacpbDogcEVMctnNrB8FIrB3vZEv9Q0Z1VeY7nmTpF+6
a+z2P7acL7j6A6Pr3+q8P9CPiPC7zFonVzuVPyB8GchGR2hytyiOVpuD9+k8hcuw
ZWAaUoVtWIQ52aKS0p19G99hhb+IVANC4akkdHV4SP8i7MVNZhfUmg==
-----END RSA PRIVATE KEY-----


-----BEGIN EMPTY-----
-----END EMPTY-----

-----BEGIN EMPTY-----

-----END EMPTY-----

-----BEGIN EMPTY-----


-----END EMPTY-----

# This shouldn't be recognised because of the missing newline after the
headers.
-----BEGIN HEADERS-----
Header: 1
-----END HEADERS-----

# This should be valid, however.
-----BEGIN HEADERS-----
Header: 1

-----END HEADERS-----`

var certificate = &Block{Type: "CERTIFICATE",
	Headers: map[string]string{},
	Bytes: []uint8{0x30, 0x82, 0x3, 0xe9, 0x30, 0x82, 0x3, 0x52, 0x2, 0x1,
		0x1, 0x30, 0xd, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd,
		0x1, 0x1, 0x5, 0x5, 0x0, 0x30, 0x81, 0x8b, 0x31, 0xb, 0x30,
		0x9, 0x6, 0x3, 0x55, 0x4, 0x6, 0x13, 0x2, 0x55, 0x53, 0x31,
		0x13, 0x30, 0x11, 0x6, 0x3, 0x55, 0x4, 0x8, 0x13, 0xa, 0x43,
		0x61, 0x6c, 0x69, 0x66, 0x6f, 0x72, 0x6e, 0x69, 0x61, 0x31,
		0x16, 0x30, 0x14, 0x6, 0x3, 0x55, 0x4, 0x7, 0x13, 0xd, 0x53,
		0x61, 0x6e, 0x20, 0x46, 0x72, 0x61, 0x6e, 0x63, 0x69, 0x73,
		0x63, 0x6f, 0x31, 0x14, 0x30, 0x12, 0x6, 0x3, 0x55, 0x4, 0xa,
		0x13, 0xb, 0x47, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x20, 0x49,
		0x6e, 0x63, 0x2e, 0x31, 0xc, 0x30, 0xa, 0x6, 0x3, 0x55, 0x4,
		0xb, 0x13, 0x3, 0x45, 0x6e, 0x67, 0x31, 0xc, 0x30, 0xa, 0x6,
		0x3, 0x55, 0x4, 0x3, 0x13, 0x3, 0x61, 0x67, 0x6c, 0x31, 0x1d,
		0x30, 0x1b, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1,
		0x9, 0x1, 0x16, 0xe, 0x61, 0x67, 0x6c, 0x40, 0x67, 0x6f, 0x6f,
		0x67, 0x6c, 0x65, 0x2e, 0x63, 0x6f, 0x6d, 0x30, 0x1e, 0x17,
		0xd, 0x30, 0x39, 0x30, 0x39, 0x30, 0x39, 0x32, 0x32, 0x30,
		0x35, 0x34, 0x33, 0x5a, 0x17, 0xd, 0x31, 0x30, 0x30, 0x39,
		0x30, 0x39, 0x32, 0x32, 0x30, 0x35, 0x34, 0x33, 0x5a, 0x30,
		0x6a, 0x31, 0xb, 0x30, 0x9, 0x6, 0x3, 0x55, 0x4, 0x6, 0x13,
		0x2, 0x41, 0x55, 0x31, 0x13, 0x30, 0x11, 0x6, 0x3, 0x55, 0x4,
		0x8, 0x13, 0xa, 0x53, 0x6f, 0x6d, 0x65, 0x2d, 0x53, 0x74, 0x61,
		0x74, 0x65, 0x31, 0x21, 0x30, 0x1f, 0x6, 0x3, 0x55, 0x4, 0xa,
		0x13, 0x18, 0x49, 0x6e, 0x74, 0x65, 0x72, 0x6e, 0x65, 0x74,
		0x20, 0x57, 0x69, 0x64, 0x67, 0x69, 0x74, 0x73, 0x20, 0x50,
		0x74, 0x79, 0x20, 0x4c, 0x74, 0x64, 0x31, 0x23, 0x30, 0x21,
		0x6, 0x3, 0x55, 0x4, 0x3, 0x13, 0x1a, 0x65, 0x75, 0x72, 0x6f,
		0x70, 0x61, 0x2e, 0x73, 0x66, 0x6f, 0x2e, 0x63, 0x6f, 0x72,
		0x70, 0x2e, 0x67, 0x6f, 0x6f, 0x67, 0x6c, 0x65, 0x2e, 0x63,
		0x6f, 0x6d, 0x30, 0x82, 0x2, 0x22, 0x30, 0xd, 0x6, 0x9, 0x2a,
		0x86, 0x48, 0x86, 0xf7, 0xd, 0x1, 0x1, 0x1, 0x5, 0x0, 0x3,
		0x82, 0x2, 0xf, 0x0, 0x30, 0x82, 0x2, 0xa, 0x2, 0x82, 0x2, 0x1,
		0x0, 0xba, 0xa6, 0x6, 0x2d, 0xef, 0xf1, 0x22, 0x6c, 0x10, 0xee,
		0x98, 0x4, 0x85, 0xf9, 0x2d, 0x2a, 0xbe, 0xa7, 0x4b, 0xfd,
		0xff, 0xa7, 0xa2, 0xe2, 0x70, 0xd9, 0x3d, 0x50, 0x73, 0xc1,
		0xa6, 0x5c, 0x5f, 0xe2, 0x89, 0x47, 0x2b, 0xb2, 0xc, 0xe1,
		0xfc, 0x57, 0x7c, 0xa4, 0x38, 0x73, 0xfd, 0x3f, 0x7a, 0x42,
		0xf, 0x48, 0xc9, 0x1e, 0x33, 0xb6, 0xe7, 0x36, 0x31, 0x7a,
		0xe6, 0x3e, 0xb6, 0xbe, 0xcc, 0xb, 0x92, 0x7f, 0x96, 0xde,
		0xbc, 0x54, 0x5e, 0x4a, 0xab, 0xe9, 0x22, 0xdf, 0x3, 0xba,
		0xfd, 0x7, 0x6c, 0x36, 0xdc, 0xaa, 0xcf, 0xd7, 0x28, 0xf7,
		0xc1, 0xb8, 0xc0, 0xde, 0xfa, 0x87, 0xfb, 0x6b, 0xd1, 0x82,
		0xcb, 0xb, 0xc0, 0x67, 0x86, 0x54, 0x25, 0xca, 0x74, 0xb6,
		0x1a, 0x83, 0xf5, 0xf2, 0x93, 0x4e, 0x35, 0x16, 0x38, 0x1c,
		0xc7, 0x63, 0x5b, 0x8d, 0x13, 0x84, 0x62, 0xb6, 0xb8, 0x66,
		0x24, 0x2a, 0xdb, 0x4, 0x65, 0xdb, 0x27, 0x6e, 0x3d, 0x6e,
		0xf8, 0x26, 0x6f, 0xb8, 0xe0, 0x74, 0x89, 0xc7, 0xd8, 0xf5,
		0x3b, 0x3d, 0x3e, 0x79, 0x86, 0xe8, 0xef, 0x3a, 0x82, 0x2c,
		0x41, 0x6d, 0xa8, 0xb1, 0x70, 0x45, 0x46, 0xea, 0xf8, 0xa4,
		0x5d, 0x70, 0x99, 0x58, 0x78, 0x5b, 0x89, 0x53, 0x2c, 0x3e,
		0xa9, 0x8d, 0xf2, 0xc, 0x51, 0xc3, 0xb, 0x20, 0x21, 0xc4, 0x5c,
		0x43, 0x7b, 0xdc, 0xf0, 0xe2, 0x73, 0xc2, 0x92, 0xdc, 0x4b,
		0x4d, 0x60, 0x2c, 0x28, 0x22, 0x57, 0x7e, 0xb6, 0x92, 0x1,
		0x8c, 0x4d, 0x50, 0x39, 0xbd, 0x4a, 0x3b, 0x2b, 0x89, 0x4,
		0xd5, 0xba, 0x12, 0xcc, 0x3d, 0x0, 0xb6, 0x67, 0xee, 0xcb,
		0x56, 0x75, 0x87, 0x4, 0xa8, 0xc, 0x2f, 0xbf, 0x6d, 0x1e, 0x80,
		0xdd, 0xad, 0x11, 0x7a, 0xa3, 0xed, 0xe, 0x3f, 0xd5, 0xc7,
		0x32, 0x3d, 0x97, 0x37, 0x3d, 0x8, 0x2, 0xdc, 0x52, 0x7c, 0x5,
		0xed, 0xa6, 0xb6, 0x59, 0x4c, 0xfb, 0xcd, 0x2a, 0x7f, 0x87,
		0x40, 0x69, 0xf, 0xdf, 0x5a, 0xf0, 0xad, 0x3a, 0xb4, 0x39,
		0xa6, 0x77, 0xde, 0xf6, 0x3b, 0x90, 0xbc, 0x2a, 0x3c, 0x63,
		0x45, 0x46, 0x94, 0x57, 0x2b, 0x4b, 0x2b, 0x3f, 0x33, 0x34,
		0xa0, 0xf4, 0xb2, 0x7f, 0xdb, 0x88, 0xd9, 0x56, 0xc, 0xd0,
		0xbd, 0xe7, 0x7f, 0x42, 0xea, 0x6c, 0xa7, 0xcf, 0x70, 0x56,
		0x27, 0x70, 0x23, 0x38, 0xed, 0xf9, 0x67, 0x52, 0x7f, 0x25,
		0x9f, 0x1f, 0x4f, 0xef, 0xd5, 0xa4, 0xb, 0xbe, 0xee, 0x5c,
		0x31, 0x8b, 0x96, 0xff, 0xf0, 0xb4, 0x5b, 0x69, 0xe5, 0x63,
		0x38, 0x8b, 0xe5, 0xb9, 0x44, 0x4e, 0x7b, 0x4c, 0xf0, 0xcc,
		0xb6, 0xc9, 0xb3, 0x40, 0x47, 0x2d, 0xc8, 0x8, 0x7c, 0x42, 0x6,
		0xfd, 0x91, 0x36, 0xd3, 0xc8, 0x59, 0x5, 0x66, 0xf8, 0x4f,
		0x7f, 0x5b, 0x9a, 0xf0, 0x87, 0x62, 0x9, 0x47, 0x80, 0xc7,
		0x9f, 0x62, 0xc7, 0xc1, 0x45, 0x66, 0x4f, 0xf8, 0x47, 0x35,
		0x37, 0x41, 0x2e, 0x5e, 0x54, 0x87, 0xa, 0xf8, 0x59, 0xce,
		0xc9, 0x84, 0x4e, 0xc0, 0x56, 0xa6, 0xf5, 0xe2, 0x95, 0x4d,
		0xcf, 0x59, 0x6b, 0xe6, 0x3c, 0x6c, 0xa7, 0xff, 0xe7, 0x70,
		0x8c, 0x1f, 0xb5, 0xbe, 0xe6, 0x65, 0xd, 0xc3, 0x17, 0x4d,
		0xd8, 0x9d, 0xaf, 0xa3, 0x26, 0x1a, 0x73, 0xc7, 0xc0, 0x90,
		0xa1, 0xe2, 0xd3, 0xe9, 0xa4, 0x2, 0x1f, 0x2c, 0xe6, 0x1f,
		0xaf, 0xc, 0xac, 0x71, 0xd3, 0xe0, 0xc0, 0xb, 0x3f, 0x25, 0x2c,
		0x3e, 0x89, 0xa3, 0x9f, 0xbd, 0x46, 0x35, 0x3b, 0x43, 0x79,
		0x60, 0x17, 0x89, 0xb8, 0xc2, 0x81, 0xd2, 0xfa, 0x88, 0x70,
		0x2, 0x8, 0x5e, 0x87, 0xb5, 0xb9, 0x74, 0xcc, 0x69, 0x46, 0xd0,
		0xe0, 0xa, 0xf9, 0xb7, 0x67, 0xd1, 0x2, 0x3, 0x1, 0x0, 0x1,
		0x30, 0xd, 0x6, 0x9, 0x2a, 0x86, 0x48, 0x86, 0xf7, 0xd, 0x1,
		0x1, 0x5, 0x5, 0x0, 0x3, 0x81, 0x81, 0x0, 0xe2, 0xa7, 0x40,
		0x3b, 0x6a, 0x5, 0x5d, 0xb8, 0xbd, 0x5a, 0xaf, 0x7a, 0xc2,
		0xf9, 0x76, 0x79, 0xb2, 0x16, 0x91, 0x4f, 0x5c, 0x19, 0xf7,
		0x59, 0xd1, 0x5f, 0xc0, 0x3e, 0x83, 0xcc, 0x46, 0xf6, 0xd5,
		0x45, 0x46, 0xe6, 0x4a, 0xe6, 0x26, 0x2b, 0xbe, 0x56, 0x28,
		0xa9, 0x39, 0x12, 0x4f, 0x18, 0xc9, 0x20, 0xa0, 0xbe, 0x81,
		0x8d, 0x4d, 0xb5, 0x5c, 0x8f, 0x79, 0x55, 0x6, 0xee, 0x9f,
		0x93, 0xfc, 0xbe, 0xf8, 0x3c, 0x67, 0xe1, 0x67, 0x16, 0xcb,
		0xd1, 0x15, 0x8d, 0xde, 0xd4, 0x20, 0xb3, 0x1, 0x54, 0x18,
		0x66, 0xc5, 0x24, 0x2f, 0xd, 0x88, 0xef, 0x32, 0x3f, 0x74,
		0xd9, 0x56, 0x74, 0x1f, 0x17, 0xa7, 0xbb, 0xfe, 0xdf, 0xf,
		0x6c, 0x5f, 0x93, 0x77, 0x27, 0xf5, 0xae, 0x27, 0x52, 0x8e,
		0x3b, 0x99, 0xb6, 0xea, 0x44, 0x65, 0x1d, 0xa, 0x3b, 0x13,
		0x34, 0xf7, 0xf7, 0xbe, 0x20,
	},
}

var privateKey = &Block{Type: "RSA PRIVATE KEY",
	Headers: map[string]string{"DEK-Info": "DES-EDE3-CBC,80C7C7A09690757A", "Proc-Type": "4,ENCRYPTED"},
	Bytes: []uint8{0x79, 0xa, 0x79, 0x66, 0x41, 0xfa, 0xb,
		0x21, 0xc1, 0xcf, 0xb0, 0x59, 0x7d, 0x43, 0xf1, 0xc8, 0xb0,
		0x82, 0x99, 0xfb, 0x6c, 0x4, 0x9e, 0xc7, 0x96, 0xa1, 0x9b,
		0xf0, 0xb7, 0x76, 0xd5, 0xc4, 0xb0, 0x9f, 0x35, 0x99, 0xe3,
		0xf4, 0x88, 0x96, 0x1c, 0xab, 0x52, 0xdb, 0x1f, 0xc3, 0xb5,
		0x51, 0xd9, 0x34, 0xf0, 0x3, 0xea, 0x1d, 0xa3, 0xd7, 0xb1,
		0xec, 0x67, 0x71, 0x39, 0x36, 0x87, 0xf2, 0x86, 0x45, 0xba,
		0x62, 0x11, 0xa2, 0x21, 0x23, 0x1e, 0xc9, 0x3c, 0x53, 0xb0,
		0x61, 0x9e, 0xda, 0x7e, 0x7a, 0x49, 0xf, 0x3f, 0xbf, 0x71,
		0xba, 0x79, 0xcd, 0xee, 0x16, 0xfb, 0x86, 0x48, 0x6b, 0xc8,
		0x60, 0xd0, 0x66, 0x0, 0x3b, 0xb3, 0x67, 0x10, 0x1d, 0xe,
		0xf5, 0xbf, 0x78, 0x30, 0x4f, 0x60, 0x40, 0x8, 0x7, 0xed,
		0xdb, 0xa8, 0xc2, 0x8d, 0xb3, 0x35, 0xc2, 0x3, 0x73, 0x6,
		0x72, 0x7c, 0x33, 0x44, 0x73, 0x9f, 0xaf, 0x18, 0x5a, 0xa6,
		0x8f, 0xb5, 0xd0, 0x6e, 0xf2, 0xa6, 0xff, 0xcd, 0x54, 0x79,
		0x24, 0x1d, 0x66, 0x9e, 0xab, 0xd3, 0x49, 0xb1, 0x6c, 0x7c,
		0x5e, 0x72, 0x31, 0xce, 0xa8, 0xd9, 0x64, 0x3d, 0x8c, 0x90,
		0xa5, 0xe8, 0xac, 0xa9, 0x9c, 0xc9, 0x7e, 0x6, 0x92, 0xfe,
		0x76, 0x5b, 0xdd, 0x8d, 0x85, 0x4a, 0xe2, 0x5f, 0x65, 0x62,
		0xc0, 0x75, 0x1e, 0xcd, 0xdd, 0xfb, 0x30, 0xc1, 0x6d, 0x6c,
		0x68, 0xb3, 0xcd, 0x7c, 0xcf, 0x38, 0x52, 0xf3, 0xfc, 0xba,
		0x78, 0x87, 0xe2, 0x48, 0x6d, 0xbb, 0x72, 0xaa, 0xdb, 0x85,
		0x44, 0x5b, 0x9a, 0x8, 0x92, 0x7c, 0x35, 0xe3, 0x9d, 0xc2,
		0xb8, 0x9b, 0xfa, 0x4b, 0x71, 0xe, 0xe6, 0x98, 0x12, 0xfa,
		0x98, 0x53, 0xab, 0xdc, 0xf8, 0xf8, 0x8d, 0xea, 0x73, 0x80,
		0xe8, 0x85, 0x44, 0xbe, 0x8c, 0x28, 0x4f, 0xff, 0x87, 0xad,
		0x9f, 0x66, 0xf2, 0x35, 0x12, 0xb6, 0x2b, 0xf1, 0x5b, 0xa7,
		0x1c, 0x4c, 0xa4, 0x80, 0xa3, 0x61, 0xa, 0x10, 0xef, 0x6f,
		0x54, 0x4e, 0xe8, 0xb1, 0x1f, 0xa8, 0xa0, 0x6e, 0xf8, 0x8b,
		0xf0, 0x4c, 0x1e, 0x9f, 0x6, 0x15, 0xb7, 0x4c, 0x22, 0xcc,
		0x9d, 0x53, 0xd8, 0x56, 0x86, 0x30, 0x3, 0xe7, 0xc7, 0x35,
		0x39, 0x99, 0x66, 0x6f, 0x1, 0x12, 0x89, 0xe5, 0x20, 0xc7,
		0xc8, 0xf8, 0xa9, 0x2d, 0x8d, 0x65, 0x20, 0xe0, 0xe8, 0x9a,
		0xf8, 0xd2, 0x3a, 0xbc, 0xa7, 0xf, 0xa4, 0x5a, 0x31, 0x85,
		0x29, 0xe5, 0x1a, 0x0, 0xad, 0xbd, 0xf1, 0x1a, 0xab, 0x9f,
		0xc7, 0xe2, 0x41, 0xc9, 0xa7, 0xde, 0x5e, 0x3a, 0x99, 0xc5,
		0xb0, 0xbb, 0xe2, 0xc3, 0x6b, 0x1e, 0x1c, 0xd9, 0x33, 0xfc,
		0xbc, 0x49, 0x31, 0x13, 0xf5, 0x5f, 0x8d, 0xbc, 0xf8, 0x3a,
		0x58, 0x5b, 0xf4, 0x3, 0xff, 0x42, 0x54, 0xb4, 0x94, 0xae,
		0xb, 0xfa, 0xbd, 0x15, 0x41, 0xcb, 0xe9, 0x12, 0x37, 0xbb,
		0xf0, 0x2c, 0xae, 0xff, 0x29, 0x9, 0xbe, 0x3e, 0xf, 0xb8,
		0xb5, 0x8d, 0x6f, 0xc0, 0x30, 0x87, 0x49, 0x4e, 0xdc, 0x9c,
		0x38, 0x6b, 0x1b, 0x3f, 0x14, 0x0, 0xef, 0x21, 0xcc, 0x5a,
		0xe8, 0xc7, 0x99, 0xe6, 0xf5, 0x5, 0x38, 0x87, 0x70, 0xbd,
		0xec, 0xdc, 0xaa, 0xc9, 0xbb, 0x5b, 0xc3, 0x56, 0xbb, 0x21,
		0xbf, 0x17, 0xe7, 0xcf, 0xbd, 0x4a, 0x4d, 0xe3, 0x67, 0x64,
		0x7f, 0x14, 0x6c, 0xea, 0x93, 0xe6, 0x2e, 0xdf, 0x3c, 0x6c,
		0x97, 0xb5, 0x8d, 0x57, 0x25, 0xd7, 0x5c, 0x6c, 0x8f, 0xd0,
		0xea, 0xd5, 0xdf, 0xc0, 0x71, 0x6c, 0x65, 0xcd, 0xb4, 0x4f,
		0x34, 0x9d, 0xb1, 0x52, 0xc1, 0xb7, 0x9, 0x2c, 0x51, 0xa7,
		0x29, 0x6c, 0x3a, 0x20, 0x70, 0x45, 0x4c, 0x72, 0xd9, 0xcd,
		0xac, 0x1f, 0x5, 0x22, 0xb0, 0x77, 0xbd, 0x91, 0x2f, 0xf5,
		0xd, 0x19, 0xd5, 0x57, 0x98, 0xee, 0x79, 0x93, 0xa4, 0x5f,
		0xba, 0x6b, 0xec, 0xf6, 0x3f, 0xb6, 0x9c, 0x2f, 0xb8, 0xfa,
		0x3, 0xa3, 0xeb, 0xdf, 0xea, 0xbc, 0x3f, 0xd0, 0x8f, 0x88,
		0xf0, 0xbb, 0xcc, 0x5a, 0x27, 0x57, 0x3b, 0x95, 0x3f, 0x20,
		0x7c, 0x19, 0xc8, 0x46, 0x47, 0x68, 0x72, 0xb7, 0x28, 0x8e,
		0x56, 0x9b, 0x83, 0xf7, 0xe9, 0x3c, 0x85, 0xcb, 0xb0, 0x65,
		0x60, 0x1a, 0x52, 0x85, 0x6d, 0x58, 0x84, 0x39, 0xd9, 0xa2,
		0x92, 0xd2, 0x9d, 0x7d, 0x1b, 0xdf, 0x61, 0x85, 0xbf, 0x88,
		0x54, 0x3, 0x42, 0xe1, 0xa9, 0x24, 0x74, 0x75, 0x78, 0x48,
		0xff, 0x22, 0xec, 0xc5, 0x4d, 0x66, 0x17, 0xd4, 0x9a,
	},
}

var privateKey2 = &Block{
	Type: "RSA PRIVATE KEY",
	Headers: map[string]string{
		"Proc-Type":      "4,ENCRYPTED",
		"DEK-Info":       "AES-128-CBC,BFCD243FEDBB40A4AA6DDAA1335473A4",
		"Content-Domain": "RFC822",
	},
	Bytes: []uint8{
		0xa8, 0x35, 0xcc, 0x2b, 0xb9, 0xcb, 0x21, 0xab, 0xc0,
		0x9d, 0x76, 0x61, 0x0, 0xf4, 0x81, 0xad, 0x69, 0xd2,
		0xc0, 0x42, 0x41, 0x3b, 0xe4, 0x3c, 0xaf, 0x59, 0x5e,
		0x6d, 0x2a, 0x3c, 0x9c, 0xa1, 0xa4, 0x5e, 0x68, 0x37,
		0xc4, 0x8c, 0x70, 0x1c, 0xa9, 0x18, 0xe6, 0xc2, 0x2b,
		0x8a, 0x91, 0xdc, 0x2d, 0x1f, 0x8, 0x23, 0x39, 0xf1,
		0x4b, 0x8b, 0x1b, 0x2f, 0x46, 0xb, 0xb2, 0x26, 0xba,
		0x4f, 0x40, 0x80, 0x39, 0xc4, 0xb1, 0xcb, 0x3b, 0xb4,
		0x65, 0x3f, 0x1b, 0xb2, 0xf7, 0x8, 0xd2, 0xc6, 0xd5,
		0xa8, 0x9f, 0x23, 0x69, 0xb6, 0x3d, 0xf9, 0xac, 0x1c,
		0xb3, 0x13, 0x87, 0x64, 0x4, 0x37, 0xdb, 0x40, 0xc8,
		0x82, 0xc, 0xd0, 0xf8, 0x21, 0x7c, 0xdc, 0xbd, 0x9, 0x4,
		0x20, 0x16, 0xb0, 0x97, 0xe2, 0x6d, 0x56, 0x1d, 0xe3,
		0xec, 0xf0, 0xfc, 0xe2, 0x56, 0xad, 0xa4, 0x3, 0x70,
		0x6d, 0x63, 0x3c, 0x1, 0xbe, 0x3e, 0x28, 0x38, 0x6f,
		0xc0, 0xe6, 0xfd, 0x85, 0xd1, 0x53, 0xa8, 0x9b, 0xcb,
		0xd4, 0x4, 0xb1, 0x73, 0xb9, 0x73, 0x32, 0xd6, 0x7a,
		0xc6, 0x29, 0x25, 0xa5, 0xda, 0x17, 0x93, 0x7a, 0x10,
		0xe8, 0x41, 0xfb, 0xa5, 0x17, 0x20, 0xf8, 0x4e, 0xe9,
		0xe3, 0x8f, 0x51, 0x20, 0x13, 0xbb, 0xde, 0xb7, 0x93,
		0xae, 0x13, 0x8a, 0xf6, 0x9, 0xf4, 0xa6, 0x41, 0xe0,
		0x2b, 0x51, 0x1a, 0x30, 0x38, 0xd, 0xb1, 0x3b, 0x67,
		0x87, 0x64, 0xf5, 0xca, 0x32, 0x67, 0xd1, 0xc8, 0xa5,
		0x3d, 0x23, 0x72, 0xc4, 0x6, 0xaf, 0x8f, 0x7b, 0x26,
		0xac, 0x3c, 0x75, 0x91, 0xa1, 0x0, 0x13, 0xc6, 0x5c,
		0x49, 0xd5, 0x3c, 0xe7, 0xb2, 0xb2, 0x99, 0xe0, 0xd5,
		0x25, 0xfa, 0xe2, 0x12, 0x80, 0x37, 0x85, 0xcf, 0x92,
		0xca, 0x1b, 0x9f, 0xf3, 0x4e, 0xd8, 0x80, 0xef, 0x3c,
		0xce, 0xcd, 0xf5, 0x90, 0x9e, 0xf9, 0xa7, 0xb2, 0xc,
		0x49, 0x4, 0xf1, 0x9, 0x8f, 0xea, 0x63, 0xd2, 0x70,
		0xbb, 0x86, 0xbf, 0x34, 0xab, 0xb2, 0x3, 0xb1, 0x59,
		0x33, 0x16, 0x17, 0xb0, 0xdb, 0x77, 0x38, 0xf4, 0xb4,
		0x94, 0xb, 0x25, 0x16, 0x7e, 0x22, 0xd4, 0xf9, 0x22,
		0xb9, 0x78, 0xa3, 0x4, 0x84, 0x4, 0xd2, 0xda, 0x84,
		0x2d, 0x63, 0xdd, 0xf8, 0x50, 0x6a, 0xf6, 0xe3, 0xf5,
		0x65, 0x40, 0x7c, 0xa9,
	},
}

var pemPrivateKey2 = `-----BEGIN RSA PRIVATE KEY-----
Proc-Type: 4,ENCRYPTED
Content-Domain: RFC822
DEK-Info: AES-128-CBC,BFCD243FEDBB40A4AA6DDAA1335473A4

qDXMK7nLIavAnXZhAPSBrWnSwEJBO+Q8r1lebSo8nKGkXmg3xIxwHKkY5sIripHc
LR8IIznxS4sbL0YLsia6T0CAOcSxyzu0ZT8bsvcI0sbVqJ8jabY9+awcsxOHZAQ3
20DIggzQ+CF83L0JBCAWsJfibVYd4+zw/OJWraQDcG1jPAG+Pig4b8Dm/YXRU6ib
y9QEsXO5czLWesYpJaXaF5N6EOhB+6UXIPhO6eOPUSATu963k64TivYJ9KZB4CtR
GjA4DbE7Z4dk9coyZ9HIpT0jcsQGr497Jqw8dZGhABPGXEnVPOeyspng1SX64hKA
N4XPksobn/NO2IDvPM7N9ZCe+aeyDEkE8QmP6mPScLuGvzSrsgOxWTMWF7Dbdzj0
tJQLJRZ+ItT5Irl4owSEBNLahC1j3fhQavbj9WVAfKk=
-----END RSA PRIVATE KEY-----
`
