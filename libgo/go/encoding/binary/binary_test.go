// Copyright 2009 The Go Authors.  All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package binary

import (
	"bytes"
	"io"
	"math"
	"reflect"
	"testing"
)

type Struct struct {
	Int8       int8
	Int16      int16
	Int32      int32
	Int64      int64
	Uint8      uint8
	Uint16     uint16
	Uint32     uint32
	Uint64     uint64
	Float32    float32
	Float64    float64
	Complex64  complex64
	Complex128 complex128
	Array      [4]uint8
}

type T struct {
	Int     int
	Uint    uint
	Uintptr uintptr
	Array   [4]int
}

var s = Struct{
	0x01,
	0x0203,
	0x04050607,
	0x08090a0b0c0d0e0f,
	0x10,
	0x1112,
	0x13141516,
	0x1718191a1b1c1d1e,

	math.Float32frombits(0x1f202122),
	math.Float64frombits(0x232425262728292a),
	complex(
		math.Float32frombits(0x2b2c2d2e),
		math.Float32frombits(0x2f303132),
	),
	complex(
		math.Float64frombits(0x333435363738393a),
		math.Float64frombits(0x3b3c3d3e3f404142),
	),

	[4]uint8{0x43, 0x44, 0x45, 0x46},
}

var big = []byte{
	1,
	2, 3,
	4, 5, 6, 7,
	8, 9, 10, 11, 12, 13, 14, 15,
	16,
	17, 18,
	19, 20, 21, 22,
	23, 24, 25, 26, 27, 28, 29, 30,

	31, 32, 33, 34,
	35, 36, 37, 38, 39, 40, 41, 42,
	43, 44, 45, 46, 47, 48, 49, 50,
	51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65, 66,

	67, 68, 69, 70,
}

var little = []byte{
	1,
	3, 2,
	7, 6, 5, 4,
	15, 14, 13, 12, 11, 10, 9, 8,
	16,
	18, 17,
	22, 21, 20, 19,
	30, 29, 28, 27, 26, 25, 24, 23,

	34, 33, 32, 31,
	42, 41, 40, 39, 38, 37, 36, 35,
	46, 45, 44, 43, 50, 49, 48, 47,
	58, 57, 56, 55, 54, 53, 52, 51, 66, 65, 64, 63, 62, 61, 60, 59,

	67, 68, 69, 70,
}

var src = []byte{1, 2, 3, 4, 5, 6, 7, 8}
var res = []int32{0x01020304, 0x05060708}

func checkResult(t *testing.T, dir string, order ByteOrder, err error, have, want interface{}) {
	if err != nil {
		t.Errorf("%v %v: %v", dir, order, err)
		return
	}
	if !reflect.DeepEqual(have, want) {
		t.Errorf("%v %v:\n\thave %+v\n\twant %+v", dir, order, have, want)
	}
}

func testRead(t *testing.T, order ByteOrder, b []byte, s1 interface{}) {
	var s2 Struct
	err := Read(bytes.NewBuffer(b), order, &s2)
	checkResult(t, "Read", order, err, s2, s1)
}

func testWrite(t *testing.T, order ByteOrder, b []byte, s1 interface{}) {
	buf := new(bytes.Buffer)
	err := Write(buf, order, s1)
	checkResult(t, "Write", order, err, buf.Bytes(), b)
}

func TestBigEndianRead(t *testing.T) { testRead(t, BigEndian, big, s) }

func TestLittleEndianRead(t *testing.T) { testRead(t, LittleEndian, little, s) }

func TestBigEndianWrite(t *testing.T) { testWrite(t, BigEndian, big, s) }

func TestLittleEndianWrite(t *testing.T) { testWrite(t, LittleEndian, little, s) }

func TestBigEndianPtrWrite(t *testing.T) { testWrite(t, BigEndian, big, &s) }

func TestLittleEndianPtrWrite(t *testing.T) { testWrite(t, LittleEndian, little, &s) }

func TestReadSlice(t *testing.T) {
	slice := make([]int32, 2)
	err := Read(bytes.NewBuffer(src), BigEndian, slice)
	checkResult(t, "ReadSlice", BigEndian, err, slice, res)
}

func TestWriteSlice(t *testing.T) {
	buf := new(bytes.Buffer)
	err := Write(buf, BigEndian, res)
	checkResult(t, "WriteSlice", BigEndian, err, buf.Bytes(), src)
}

func TestWriteT(t *testing.T) {
	buf := new(bytes.Buffer)
	ts := T{}
	err := Write(buf, BigEndian, ts)
	if err == nil {
		t.Errorf("WriteT: have nil, want non-nil")
	}

	tv := reflect.Indirect(reflect.ValueOf(ts))
	for i, n := 0, tv.NumField(); i < n; i++ {
		err = Write(buf, BigEndian, tv.Field(i).Interface())
		if err == nil {
			t.Errorf("WriteT.%v: have nil, want non-nil", tv.Field(i).Type())
		}
	}
}

type byteSliceReader struct {
	remain []byte
}

func (br *byteSliceReader) Read(p []byte) (int, error) {
	n := copy(p, br.remain)
	br.remain = br.remain[n:]
	return n, nil
}

func BenchmarkRead(b *testing.B) {
	var ls Struct
	bsr := &byteSliceReader{}
	var r io.Reader = bsr

	for i := 0; i < b.N; i++ {
		bsr.remain = big
		Read(r, BigEndian, &ls.Int8)
		Read(r, BigEndian, &ls.Int16)
		Read(r, BigEndian, &ls.Int32)
		Read(r, BigEndian, &ls.Int64)
		Read(r, BigEndian, &ls.Uint8)
		Read(r, BigEndian, &ls.Uint16)
		Read(r, BigEndian, &ls.Uint32)
		Read(r, BigEndian, &ls.Uint64)
	}

	want := s
	want.Float32 = 0
	want.Float64 = 0
	want.Complex64 = 0
	want.Complex128 = 0
	for i := range want.Array {
		want.Array[i] = 0
	}
	if !reflect.DeepEqual(ls, want) {
		panic("no match")
	}
}

func BenchmarkWrite(b *testing.B) {
	buf := new(bytes.Buffer)
	var w io.Writer = buf

	for i := 0; i < b.N; i++ {
		buf.Reset()
		Write(w, BigEndian, &s.Int8)
		Write(w, BigEndian, &s.Int16)
		Write(w, BigEndian, &s.Int32)
		Write(w, BigEndian, &s.Int64)
		Write(w, BigEndian, &s.Uint8)
		Write(w, BigEndian, &s.Uint16)
		Write(w, BigEndian, &s.Uint32)
		Write(w, BigEndian, &s.Uint64)
		Write(w, BigEndian, s.Int8)
		Write(w, BigEndian, s.Int16)
		Write(w, BigEndian, s.Int32)
		Write(w, BigEndian, s.Int64)
		Write(w, BigEndian, s.Uint8)
		Write(w, BigEndian, s.Uint16)
		Write(w, BigEndian, s.Uint32)
		Write(w, BigEndian, s.Uint64)
	}

	if !bytes.Equal(buf.Bytes()[:30], big[:30]) {
		panic("first half doesn't match")
	}
	if !bytes.Equal(buf.Bytes()[30:], big[:30]) {
		panic("second half doesn't match")
	}
}
