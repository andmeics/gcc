// Copyright 2017 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build !plan9,!windows

#include <stdint.h>

uint32_t threadExited;

void setExited(void *x) {
	__atomic_add_fetch(&threadExited, 1, __ATOMIC_SEQ_CST);
}
