// Copyright 2015 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// +build gc

package main_test

import (
	"go/build"
	"runtime"
	"testing"

	"cmd/internal/buildid"
)

func TestNoteReading(t *testing.T) {
	// cmd/internal/buildid already has tests that the basic reading works.
	// This test is essentially checking that -ldflags=-buildid=XXX works,
	// both in internal and external linking mode.
	tg := testgo(t)
	defer tg.cleanup()
	tg.tempFile("hello.go", `package main; func main() { print("hello, world\n") }`)
	const buildID = "TestNoteReading-Build-ID"
	tg.run("build", "-ldflags", "-buildid="+buildID, "-o", tg.path("hello.exe"), tg.path("hello.go"))
	id, err := buildid.ReadFile(tg.path("hello.exe"))
	if err != nil {
		t.Fatalf("reading build ID from hello binary: %v", err)
	}
	if id != buildID {
		t.Fatalf("buildID in hello binary = %q, want %q", id, buildID)
	}

	switch {
	case !build.Default.CgoEnabled:
		t.Skipf("skipping - no cgo, so assuming external linking not available")
	case runtime.GOOS == "openbsd" && runtime.GOARCH == "arm":
		t.Skipf("skipping - external linking not supported, golang.org/issue/10619")
	case runtime.GOOS == "plan9":
		t.Skipf("skipping - external linking not supported")
	}

	tg.run("build", "-ldflags", "-buildid="+buildID+" -linkmode=external", "-o", tg.path("hello2.exe"), tg.path("hello.go"))
	id, err = buildid.ReadFile(tg.path("hello2.exe"))
	if err != nil {
		t.Fatalf("reading build ID from hello binary (linkmode=external): %v", err)
	}
	if id != buildID {
		t.Fatalf("buildID in hello binary = %q, want %q (linkmode=external)", id, buildID)
	}

	switch runtime.GOOS {
	case "dragonfly", "freebsd", "linux", "netbsd", "openbsd":
		// Test while forcing use of the gold linker, since in the past
		// we've had trouble reading the notes generated by gold.
		err := tg.doRun([]string{"build", "-ldflags", "-buildid=" + buildID + " -linkmode=external -extldflags=-fuse-ld=gold", "-o", tg.path("hello3.exe"), tg.path("hello.go")})
		if err != nil {
			if tg.grepCountBoth("(invalid linker|gold|cannot find 'ld')") > 0 {
				// It's not an error if gold isn't there. gcc claims it "cannot find 'ld'" if
				// ld.gold is missing, see issue #22340.
				t.Log("skipping gold test")
				break
			}
			t.Fatalf("building hello binary: %v", err)
		}
		id, err = buildid.ReadFile(tg.path("hello3.exe"))
		if err != nil {
			t.Fatalf("reading build ID from hello binary (linkmode=external -extldflags=-fuse-ld=gold): %v", err)
		}
		if id != buildID {
			t.Fatalf("buildID in hello binary = %q, want %q (linkmode=external -extldflags=-fuse-ld=gold)", id, buildID)
		}
	}
}
