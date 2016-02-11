// Copyright 2012 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package httptest

import (
	"fmt"
	"io"
	"net/http"
	"testing"
)

func TestRecorder(t *testing.T) {
	type checkFunc func(*ResponseRecorder) error
	check := func(fns ...checkFunc) []checkFunc { return fns }

	hasStatus := func(wantCode int) checkFunc {
		return func(rec *ResponseRecorder) error {
			if rec.Code != wantCode {
				return fmt.Errorf("Status = %d; want %d", rec.Code, wantCode)
			}
			return nil
		}
	}
	hasContents := func(want string) checkFunc {
		return func(rec *ResponseRecorder) error {
			if rec.Body.String() != want {
				return fmt.Errorf("wrote = %q; want %q", rec.Body.String(), want)
			}
			return nil
		}
	}
	hasFlush := func(want bool) checkFunc {
		return func(rec *ResponseRecorder) error {
			if rec.Flushed != want {
				return fmt.Errorf("Flushed = %v; want %v", rec.Flushed, want)
			}
			return nil
		}
	}
	hasHeader := func(key, want string) checkFunc {
		return func(rec *ResponseRecorder) error {
			if got := rec.HeaderMap.Get(key); got != want {
				return fmt.Errorf("header %s = %q; want %q", key, got, want)
			}
			return nil
		}
	}

	tests := []struct {
		name   string
		h      func(w http.ResponseWriter, r *http.Request)
		checks []checkFunc
	}{
		{
			"200 default",
			func(w http.ResponseWriter, r *http.Request) {},
			check(hasStatus(200), hasContents("")),
		},
		{
			"first code only",
			func(w http.ResponseWriter, r *http.Request) {
				w.WriteHeader(201)
				w.WriteHeader(202)
				w.Write([]byte("hi"))
			},
			check(hasStatus(201), hasContents("hi")),
		},
		{
			"write sends 200",
			func(w http.ResponseWriter, r *http.Request) {
				w.Write([]byte("hi first"))
				w.WriteHeader(201)
				w.WriteHeader(202)
			},
			check(hasStatus(200), hasContents("hi first"), hasFlush(false)),
		},
		{
			"write string",
			func(w http.ResponseWriter, r *http.Request) {
				io.WriteString(w, "hi first")
			},
			check(
				hasStatus(200),
				hasContents("hi first"),
				hasFlush(false),
				hasHeader("Content-Type", "text/plain; charset=utf-8"),
			),
		},
		{
			"flush",
			func(w http.ResponseWriter, r *http.Request) {
				w.(http.Flusher).Flush() // also sends a 200
				w.WriteHeader(201)
			},
			check(hasStatus(200), hasFlush(true)),
		},
		{
			"Content-Type detection",
			func(w http.ResponseWriter, r *http.Request) {
				io.WriteString(w, "<html>")
			},
			check(hasHeader("Content-Type", "text/html; charset=utf-8")),
		},
		{
			"no Content-Type detection with Transfer-Encoding",
			func(w http.ResponseWriter, r *http.Request) {
				w.Header().Set("Transfer-Encoding", "some encoding")
				io.WriteString(w, "<html>")
			},
			check(hasHeader("Content-Type", "")), // no header
		},
		{
			"no Content-Type detection if set explicitly",
			func(w http.ResponseWriter, r *http.Request) {
				w.Header().Set("Content-Type", "some/type")
				io.WriteString(w, "<html>")
			},
			check(hasHeader("Content-Type", "some/type")),
		},
		{
			"Content-Type detection doesn't crash if HeaderMap is nil",
			func(w http.ResponseWriter, r *http.Request) {
				// Act as if the user wrote new(httptest.ResponseRecorder)
				// rather than using NewRecorder (which initializes
				// HeaderMap)
				w.(*ResponseRecorder).HeaderMap = nil
				io.WriteString(w, "<html>")
			},
			check(hasHeader("Content-Type", "text/html; charset=utf-8")),
		},
	}
	r, _ := http.NewRequest("GET", "http://foo.com/", nil)
	for _, tt := range tests {
		h := http.HandlerFunc(tt.h)
		rec := NewRecorder()
		h.ServeHTTP(rec, r)
		for _, check := range tt.checks {
			if err := check(rec); err != nil {
				t.Errorf("%s: %v", tt.name, err)
			}
		}
	}
}
