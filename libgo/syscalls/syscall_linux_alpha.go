// syscall_linux_alpha.go -- GNU/Linux ALPHA specific support

// Copyright 2011 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package syscall

func (r *PtraceRegs) PC() uint64 {
	return r.Pc;
}

func (r *PtraceRegs) SetPC(pc uint64) {
	r.Pc = pc;
}
