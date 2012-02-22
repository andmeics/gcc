// Copyright 2012 The Go Authors.  All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package main

import (
	"runtime"
	"testing"
)

func TestSpec(t *testing.T) {
	if err := verify(runtime.GOROOT()+"/doc/go_spec.html", "SourceFile", nil); err != nil {
		t.Fatal(err)
	}
}
