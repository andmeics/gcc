// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build aix darwin dragonfly freebsd linux netbsd openbsd solaris nacl

// Read system port mappings from /etc/services

package net

import "sync"

var onceReadServices sync.Once

func readServices() {
	file, err := open("/etc/services")
	if err != nil {
		return
	}
	for line, ok := file.readLine(); ok; line, ok = file.readLine() {
		// "http 80/tcp www www-http # World Wide Web HTTP"
		if i := byteIndex(line, '#'); i >= 0 {
			line = line[:i]
		}
		f := getFields(line)
		if len(f) < 2 {
			continue
		}
		portnet := f[1] // "80/tcp"
		port, j, ok := dtoi(portnet)
		if !ok || port <= 0 || j >= len(portnet) || portnet[j] != '/' {
			continue
		}
		netw := portnet[j+1:] // "tcp"
		m, ok1 := services[netw]
		if !ok1 {
			m = make(map[string]int)
			services[netw] = m
		}
		for i := 0; i < len(f); i++ {
			if i != 1 { // f[1] was port/net
				m[f[i]] = port
			}
		}
	}
	file.close()
}

// goLookupPort is the native Go implementation of LookupPort.
func goLookupPort(network, service string) (port int, err error) {
	onceReadServices.Do(readServices)
	return lookupPortMap(network, service)
}
