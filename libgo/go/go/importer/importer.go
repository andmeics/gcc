// Copyright 2015 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

// Package importer provides access to export data importers.
package importer

import (
	"go/build"
	"go/internal/gccgoimporter"
	"go/internal/gcimporter"
	"go/internal/srcimporter"
	"go/token"
	"go/types"
	"io"
	"runtime"
)

// A Lookup function returns a reader to access package data for
// a given import path, or an error if no matching package is found.
type Lookup func(path string) (io.ReadCloser, error)

// For returns an Importer for importing from installed packages
// for the compilers "gc" and "gccgo", or for importing directly
// from the source if the compiler argument is "source". In this
// latter case, importing may fail under circumstances where the
// exported API is not entirely defined in pure Go source code
// (if the package API depends on cgo-defined entities, the type
// checker won't have access to those).
//
// If lookup is nil, the default package lookup mechanism for the
// given compiler is used.
//
// BUG(issue13847): For does not support non-nil lookup functions.
func For(compiler string, lookup Lookup) types.Importer {
	switch compiler {
	case "gc":
		if lookup != nil {
			panic("gc importer for custom import path lookup not supported (issue #13847).")
		}

		return make(gcimports)

	case "gccgo":
		if lookup != nil {
			panic("gccgo importer for custom import path lookup not supported (issue #13847).")
		}

		var inst gccgoimporter.GccgoInstallation
		if err := inst.InitFromDriver("gccgo"); err != nil {
			return nil
		}
		return &gccgoimports{
			packages: make(map[string]*types.Package),
			importer: inst.GetImporter(nil, nil),
		}

	case "source":
		if lookup != nil {
			panic("source importer for custom import path lookup not supported (issue #13847).")
		}

		return srcimporter.New(&build.Default, token.NewFileSet(), make(map[string]*types.Package))
	}

	// compiler not supported
	return nil
}

// Default returns an Importer for the compiler that built the running binary.
// If available, the result implements types.ImporterFrom.
func Default() types.Importer {
	return For(runtime.Compiler, nil)
}

// gc importer

type gcimports map[string]*types.Package

func (m gcimports) Import(path string) (*types.Package, error) {
	return m.ImportFrom(path, "" /* no vendoring */, 0)
}

func (m gcimports) ImportFrom(path, srcDir string, mode types.ImportMode) (*types.Package, error) {
	if mode != 0 {
		panic("mode must be 0")
	}
	return gcimporter.Import(m, path, srcDir)
}

// gccgo importer

type gccgoimports struct {
	packages map[string]*types.Package
	importer gccgoimporter.Importer
}

func (m *gccgoimports) Import(path string) (*types.Package, error) {
	return m.ImportFrom(path, "" /* no vendoring */, 0)
}

func (m *gccgoimports) ImportFrom(path, srcDir string, mode types.ImportMode) (*types.Package, error) {
	if mode != 0 {
		panic("mode must be 0")
	}
	// TODO(gri) pass srcDir
	return m.importer(m.packages, path)
}
