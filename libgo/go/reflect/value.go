// Copyright 2009 The Go Authors. All rights reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

package reflect

import (
	"math"
	"runtime"
	"strconv"
	"unsafe"
)

const bigEndian = false // can be smarter if we find a big-endian machine
const ptrSize = unsafe.Sizeof((*byte)(nil))
const cannotSet = "cannot set value obtained from unexported struct field"

// TODO: This will have to go away when
// the new gc goes in.
func memmove(adst, asrc unsafe.Pointer, n uintptr) {
	dst := uintptr(adst)
	src := uintptr(asrc)
	switch {
	case src < dst && src+n > dst:
		// byte copy backward
		// careful: i is unsigned
		for i := n; i > 0; {
			i--
			*(*byte)(unsafe.Pointer(dst + i)) = *(*byte)(unsafe.Pointer(src + i))
		}
	case (n|src|dst)&(ptrSize-1) != 0:
		// byte copy forward
		for i := uintptr(0); i < n; i++ {
			*(*byte)(unsafe.Pointer(dst + i)) = *(*byte)(unsafe.Pointer(src + i))
		}
	default:
		// word copy forward
		for i := uintptr(0); i < n; i += ptrSize {
			*(*uintptr)(unsafe.Pointer(dst + i)) = *(*uintptr)(unsafe.Pointer(src + i))
		}
	}
}

// Value is the reflection interface to a Go value.
//
// Not all methods apply to all kinds of values.  Restrictions,
// if any, are noted in the documentation for each method.
// Use the Kind method to find out the kind of value before
// calling kind-specific methods.  Calling a method
// inappropriate to the kind of type causes a run time panic.
//
// The zero Value represents no value.
// Its IsValid method returns false, its Kind method returns Invalid,
// its String method returns "<invalid Value>", and all other methods panic.
// Most functions and methods never return an invalid value.
// If one does, its documentation states the conditions explicitly.
type Value struct {
	// typ holds the type of the value represented by a Value.
	typ *commonType

	// val holds the 1-word representation of the value.
	// If flag's flagIndir bit is set, then val is a pointer to the data.
	// Otherwise val is a word holding the actual data.
	// When the data is smaller than a word, it begins at
	// the first byte (in the memory address sense) of val.
	// We use unsafe.Pointer so that the garbage collector
	// knows that val could be a pointer.
	val unsafe.Pointer

	// flag holds metadata about the value.
	// The lowest bits are flag bits:
	//	- flagRO: obtained via unexported field, so read-only
	//	- flagIndir: val holds a pointer to the data
	//	- flagAddr: v.CanAddr is true (implies flagIndir)
	//	- flagMethod: v is a method value.
	// The next five bits give the Kind of the value.
	// This repeats typ.Kind() except for method values.
	// The remaining 23+ bits give a method number for method values.
	// If flag.kind() != Func, code can assume that flagMethod is unset.
	// If typ.size > ptrSize, code can assume that flagIndir is set.
	flag

	// A method value represents a curried method invocation
	// like r.Read for some receiver r.  The typ+val+flag bits describe
	// the receiver r, but the flag's Kind bits say Func (methods are
	// functions), and the top bits of the flag give the method number
	// in r's type's method table.
}

type flag uintptr

const (
	flagRO flag = 1 << iota
	flagIndir
	flagAddr
	flagMethod
	flagKindShift        = iota
	flagKindWidth        = 5 // there are 27 kinds
	flagKindMask    flag = 1<<flagKindWidth - 1
	flagMethodShift      = flagKindShift + flagKindWidth
)

func (f flag) kind() Kind {
	return Kind((f >> flagKindShift) & flagKindMask)
}

// A ValueError occurs when a Value method is invoked on
// a Value that does not support it.  Such cases are documented
// in the description of each method.
type ValueError struct {
	Method string
	Kind   Kind
}

func (e *ValueError) Error() string {
	if e.Kind == 0 {
		return "reflect: call of " + e.Method + " on zero Value"
	}
	return "reflect: call of " + e.Method + " on " + e.Kind.String() + " Value"
}

// methodName returns the name of the calling method,
// assumed to be two stack frames above.
func methodName() string {
	pc, _, _, _ := runtime.Caller(2)
	f := runtime.FuncForPC(pc)
	if f == nil {
		return "unknown method"
	}
	return f.Name()
}

// An iword is the word that would be stored in an
// interface to represent a given value v.  Specifically, if v is
// bigger than a pointer, its word is a pointer to v's data.
// Otherwise, its word holds the data stored
// in its leading bytes (so is not a pointer).
// Because the value sometimes holds a pointer, we use
// unsafe.Pointer to represent it, so that if iword appears
// in a struct, the garbage collector knows that might be
// a pointer.
type iword unsafe.Pointer

func (v Value) iword() iword {
	if v.flag&flagIndir != 0 && (v.kind() == Ptr || v.kind() == UnsafePointer) {
		// Have indirect but want direct word.
		return loadIword(v.val, v.typ.size)
	}
	return iword(v.val)
}

// loadIword loads n bytes at p from memory into an iword.
func loadIword(p unsafe.Pointer, n uintptr) iword {
	// Run the copy ourselves instead of calling memmove
	// to avoid moving w to the heap.
	var w iword
	switch n {
	default:
		panic("reflect: internal error: loadIword of " + strconv.Itoa(int(n)) + "-byte value")
	case 0:
	case 1:
		*(*uint8)(unsafe.Pointer(&w)) = *(*uint8)(p)
	case 2:
		*(*uint16)(unsafe.Pointer(&w)) = *(*uint16)(p)
	case 3:
		*(*[3]byte)(unsafe.Pointer(&w)) = *(*[3]byte)(p)
	case 4:
		*(*uint32)(unsafe.Pointer(&w)) = *(*uint32)(p)
	case 5:
		*(*[5]byte)(unsafe.Pointer(&w)) = *(*[5]byte)(p)
	case 6:
		*(*[6]byte)(unsafe.Pointer(&w)) = *(*[6]byte)(p)
	case 7:
		*(*[7]byte)(unsafe.Pointer(&w)) = *(*[7]byte)(p)
	case 8:
		*(*uint64)(unsafe.Pointer(&w)) = *(*uint64)(p)
	}
	return w
}

// storeIword stores n bytes from w into p.
func storeIword(p unsafe.Pointer, w iword, n uintptr) {
	// Run the copy ourselves instead of calling memmove
	// to avoid moving w to the heap.
	switch n {
	default:
		panic("reflect: internal error: storeIword of " + strconv.Itoa(int(n)) + "-byte value")
	case 0:
	case 1:
		*(*uint8)(p) = *(*uint8)(unsafe.Pointer(&w))
	case 2:
		*(*uint16)(p) = *(*uint16)(unsafe.Pointer(&w))
	case 3:
		*(*[3]byte)(p) = *(*[3]byte)(unsafe.Pointer(&w))
	case 4:
		*(*uint32)(p) = *(*uint32)(unsafe.Pointer(&w))
	case 5:
		*(*[5]byte)(p) = *(*[5]byte)(unsafe.Pointer(&w))
	case 6:
		*(*[6]byte)(p) = *(*[6]byte)(unsafe.Pointer(&w))
	case 7:
		*(*[7]byte)(p) = *(*[7]byte)(unsafe.Pointer(&w))
	case 8:
		*(*uint64)(p) = *(*uint64)(unsafe.Pointer(&w))
	}
}

// emptyInterface is the header for an interface{} value.
type emptyInterface struct {
	typ  *runtime.Type
	word iword
}

// nonEmptyInterface is the header for a interface value with methods.
type nonEmptyInterface struct {
	// see ../runtime/iface.c:/Itab
	itab *struct {
		typ    *runtime.Type // dynamic concrete type
		fun    [100000]unsafe.Pointer // method table
	}
	word iword
}

// mustBe panics if f's kind is not expected.
// Making this a method on flag instead of on Value
// (and embedding flag in Value) means that we can write
// the very clear v.mustBe(Bool) and have it compile into
// v.flag.mustBe(Bool), which will only bother to copy the
// single important word for the receiver.
func (f flag) mustBe(expected Kind) {
	k := f.kind()
	if k != expected {
		panic(&ValueError{methodName(), k})
	}
}

// mustBeExported panics if f records that the value was obtained using
// an unexported field.
func (f flag) mustBeExported() {
	if f == 0 {
		panic(&ValueError{methodName(), 0})
	}
	if f&flagRO != 0 {
		panic(methodName() + " using value obtained using unexported field")
	}
}

// mustBeAssignable panics if f records that the value is not assignable,
// which is to say that either it was obtained using an unexported field
// or it is not addressable.
func (f flag) mustBeAssignable() {
	if f == 0 {
		panic(&ValueError{methodName(), Invalid})
	}
	// Assignable if addressable and not read-only.
	if f&flagRO != 0 {
		panic(methodName() + " using value obtained using unexported field")
	}
	if f&flagAddr == 0 {
		panic(methodName() + " using unaddressable value")
	}
}

// Addr returns a pointer value representing the address of v.
// It panics if CanAddr() returns false.
// Addr is typically used to obtain a pointer to a struct field
// or slice element in order to call a method that requires a
// pointer receiver.
func (v Value) Addr() Value {
	if v.flag&flagAddr == 0 {
		panic("reflect.Value.Addr of unaddressable value")
	}
	return Value{v.typ.ptrTo(), v.val, (v.flag & flagRO) | flag(Ptr)<<flagKindShift}
}

// Bool returns v's underlying value.
// It panics if v's kind is not Bool.
func (v Value) Bool() bool {
	v.mustBe(Bool)
	if v.flag&flagIndir != 0 {
		return *(*bool)(v.val)
	}
	return *(*bool)(unsafe.Pointer(&v.val))
}

// Bytes returns v's underlying value.
// It panics if v's underlying value is not a slice of bytes.
func (v Value) Bytes() []byte {
	v.mustBe(Slice)
	if v.typ.Elem().Kind() != Uint8 {
		panic("reflect.Value.Bytes of non-byte slice")
	}
	// Slice is always bigger than a word; assume flagIndir.
	return *(*[]byte)(v.val)
}

// CanAddr returns true if the value's address can be obtained with Addr.
// Such values are called addressable.  A value is addressable if it is
// an element of a slice, an element of an addressable array,
// a field of an addressable struct, or the result of dereferencing a pointer.
// If CanAddr returns false, calling Addr will panic.
func (v Value) CanAddr() bool {
	return v.flag&flagAddr != 0
}

// CanSet returns true if the value of v can be changed.
// A Value can be changed only if it is addressable and was not
// obtained by the use of unexported struct fields.
// If CanSet returns false, calling Set or any type-specific
// setter (e.g., SetBool, SetInt64) will panic.
func (v Value) CanSet() bool {
	return v.flag&(flagAddr|flagRO) == flagAddr
}

// Call calls the function v with the input arguments in.
// For example, if len(in) == 3, v.Call(in) represents the Go call v(in[0], in[1], in[2]).
// Call panics if v's Kind is not Func.
// It returns the output results as Values.
// As in Go, each input argument must be assignable to the
// type of the function's corresponding input parameter.
// If v is a variadic function, Call creates the variadic slice parameter
// itself, copying in the corresponding values.
func (v Value) Call(in []Value) []Value {
	v.mustBe(Func)
	v.mustBeExported()
	return v.call("Call", in)
}

// CallSlice calls the variadic function v with the input arguments in,
// assigning the slice in[len(in)-1] to v's final variadic argument.  
// For example, if len(in) == 3, v.Call(in) represents the Go call v(in[0], in[1], in[2]...).
// Call panics if v's Kind is not Func or if v is not variadic.
// It returns the output results as Values.
// As in Go, each input argument must be assignable to the
// type of the function's corresponding input parameter.
func (v Value) CallSlice(in []Value) []Value {
	v.mustBe(Func)
	v.mustBeExported()
	return v.call("CallSlice", in)
}

func (v Value) call(method string, in []Value) []Value {
	// Get function pointer, type.
	t := v.typ
	var (
		fn   unsafe.Pointer
		rcvr iword
	)
	if v.flag&flagMethod != 0 {
		i := int(v.flag) >> flagMethodShift
		if v.typ.Kind() == Interface {
			tt := (*interfaceType)(unsafe.Pointer(v.typ))
			if i < 0 || i >= len(tt.methods) {
				panic("reflect: broken Value")
			}
			m := &tt.methods[i]
			if m.pkgPath != nil {
				panic(method + " of unexported method")
			}
			t = toCommonType(m.typ)
			iface := (*nonEmptyInterface)(v.val)
			if iface.itab == nil {
				panic(method + " of method on nil interface value")
			}
			fn = iface.itab.fun[i]
			rcvr = iface.word
		} else {
			ut := v.typ.uncommon()
			if ut == nil || i < 0 || i >= len(ut.methods) {
				panic("reflect: broken Value")
			}
			m := &ut.methods[i]
			if m.pkgPath != nil {
				panic(method + " of unexported method")
			}
			fn = m.tfn
			t = toCommonType(m.mtyp)
			rcvr = v.iword()
		}
	} else if v.flag&flagIndir != 0 {
		fn = *(*unsafe.Pointer)(v.val)
	} else {
		fn = v.val
	}

	if fn == nil {
		panic("reflect.Value.Call: call of nil function")
	}

	isSlice := method == "CallSlice"
	n := t.NumIn()
	if isSlice {
		if !t.IsVariadic() {
			panic("reflect: CallSlice of non-variadic function")
		}
		if len(in) < n {
			panic("reflect: CallSlice with too few input arguments")
		}
		if len(in) > n {
			panic("reflect: CallSlice with too many input arguments")
		}
	} else {
		if t.IsVariadic() {
			n--
		}
		if len(in) < n {
			panic("reflect: Call with too few input arguments")
		}
		if !t.IsVariadic() && len(in) > n {
			panic("reflect: Call with too many input arguments")
		}
	}
	for _, x := range in {
		if x.Kind() == Invalid {
			panic("reflect: " + method + " using zero Value argument")
		}
	}
	for i := 0; i < n; i++ {
		if xt, targ := in[i].Type(), t.In(i); !xt.AssignableTo(targ) {
			panic("reflect: " + method + " using " + xt.String() + " as type " + targ.String())
		}
	}
	if !isSlice && t.IsVariadic() {
		// prepare slice for remaining values
		m := len(in) - n
		slice := MakeSlice(t.In(n), m, m)
		elem := t.In(n).Elem()
		for i := 0; i < m; i++ {
			x := in[n+i]
			if xt := x.Type(); !xt.AssignableTo(elem) {
				panic("reflect: cannot use " + xt.String() + " as type " + elem.String() + " in " + method)
			}
			slice.Index(i).Set(x)
		}
		origIn := in
		in = make([]Value, n+1)
		copy(in[:n], origIn)
		in[n] = slice
	}

	nin := len(in)
	if nin != t.NumIn() {
		panic("reflect.Value.Call: wrong argument count")
	}
	nout := t.NumOut()

	if v.flag&flagMethod != 0 {
		nin++
	}
	params := make([]unsafe.Pointer, nin)
	delta := 0
	off := 0
	if v.flag&flagMethod != 0 {
		// Hard-wired first argument.
		p := new(iword)
		*p = rcvr
		params[0] = unsafe.Pointer(p)
		off = 1
	}
	first_pointer := false
	for i, pv := range in {
		pv.mustBeExported()
		targ := t.In(i).(*commonType)
		pv = pv.assignTo("reflect.Value.Call", targ, nil)
		if pv.flag&flagIndir == 0 {
			p := new(unsafe.Pointer)
			*p = pv.val
			params[off] = unsafe.Pointer(p)
		} else {
			params[off] = pv.val
		}
		if i == 0 && Kind(targ.kind) != Ptr && v.flag&flagMethod == 0 && isMethod(v.typ) {
			p := new(unsafe.Pointer)
			*p = params[off]
			params[off] = unsafe.Pointer(p)
			first_pointer = true
		}
		off++
	}

	ret := make([]Value, nout)
	results := make([]unsafe.Pointer, nout)
	for i := 0; i < nout; i++ {
		v := New(t.Out(i))
		results[i] = unsafe.Pointer(v.Pointer())
		ret[i] = Indirect(v)
	}

	var pp *unsafe.Pointer
	if len(params) > 0 {
		pp = &params[0]
	}
	var pr *unsafe.Pointer
	if len(results) > 0 {
		pr = &results[0]
	}

	call(t, fn, v.flag&flagMethod != 0, first_pointer, pp, pr)

	return ret
}

// gccgo specific test to see if typ is a method.  We can tell by
// looking at the string to see if there is a receiver.  We need this
// because for gccgo all methods take pointer receivers.
func isMethod(t *commonType) bool {
	if Kind(t.kind) != Func {
		return false
	}
	s := *t.string
	parens := 0
	params := 0
	sawRet := false
	for i, c := range s {
		if c == '(' {
			parens++
			params++
		} else if c == ')' {
			parens--
		} else if parens == 0 && c == ' ' && s[i + 1] != '(' && !sawRet {
			params++
			sawRet = true
		}
	}
	return params > 2
}

// Cap returns v's capacity.
// It panics if v's Kind is not Array, Chan, or Slice.
func (v Value) Cap() int {
	k := v.kind()
	switch k {
	case Array:
		return v.typ.Len()
	case Chan:
		return int(chancap(*(*iword)(v.iword())))
	case Slice:
		// Slice is always bigger than a word; assume flagIndir.
		return (*SliceHeader)(v.val).Cap
	}
	panic(&ValueError{"reflect.Value.Cap", k})
}

// Close closes the channel v.
// It panics if v's Kind is not Chan.
func (v Value) Close() {
	v.mustBe(Chan)
	v.mustBeExported()
	chanclose(*(*iword)(v.iword()))
}

// Complex returns v's underlying value, as a complex128.
// It panics if v's Kind is not Complex64 or Complex128
func (v Value) Complex() complex128 {
	k := v.kind()
	switch k {
	case Complex64:
		if v.flag&flagIndir != 0 {
			return complex128(*(*complex64)(v.val))
		}
		return complex128(*(*complex64)(unsafe.Pointer(&v.val)))
	case Complex128:
		// complex128 is always bigger than a word; assume flagIndir.
		return *(*complex128)(v.val)
	}
	panic(&ValueError{"reflect.Value.Complex", k})
}

// Elem returns the value that the interface v contains
// or that the pointer v points to.
// It panics if v's Kind is not Interface or Ptr.
// It returns the zero Value if v is nil.
func (v Value) Elem() Value {
	k := v.kind()
	switch k {
	case Interface:
		var (
			typ *commonType
			val unsafe.Pointer
		)
		if v.typ.NumMethod() == 0 {
			eface := (*emptyInterface)(v.val)
			if eface.typ == nil {
				// nil interface value
				return Value{}
			}
			typ = toCommonType(eface.typ)
			val = unsafe.Pointer(eface.word)
		} else {
			iface := (*nonEmptyInterface)(v.val)
			if iface.itab == nil {
				// nil interface value
				return Value{}
			}
			typ = toCommonType(iface.itab.typ)
			val = unsafe.Pointer(iface.word)
		}
		fl := v.flag & flagRO
		fl |= flag(typ.Kind()) << flagKindShift
		if typ.Kind() != Ptr && typ.Kind() != UnsafePointer {
			fl |= flagIndir
		}
		return Value{typ, val, fl}

	case Ptr:
		val := v.val
		if v.flag&flagIndir != 0 {
			val = *(*unsafe.Pointer)(val)
		}
		// The returned value's address is v's value.
		if val == nil {
			return Value{}
		}
		tt := (*ptrType)(unsafe.Pointer(v.typ))
		typ := toCommonType(tt.elem)
		fl := v.flag&flagRO | flagIndir | flagAddr
		fl |= flag(typ.Kind() << flagKindShift)
		return Value{typ, val, fl}
	}
	panic(&ValueError{"reflect.Value.Elem", k})
}

// Field returns the i'th field of the struct v.
// It panics if v's Kind is not Struct or i is out of range.
func (v Value) Field(i int) Value {
	v.mustBe(Struct)
	tt := (*structType)(unsafe.Pointer(v.typ))
	if i < 0 || i >= len(tt.fields) {
		panic("reflect: Field index out of range")
	}
	field := &tt.fields[i]
	typ := toCommonType(field.typ)

	// Inherit permission bits from v.
	fl := v.flag & (flagRO | flagIndir | flagAddr)
	// Using an unexported field forces flagRO.
	if field.pkgPath != nil {
		fl |= flagRO
	}
	fl |= flag(typ.Kind()) << flagKindShift

	var val unsafe.Pointer
	switch {
	case fl&flagIndir != 0:
		// Indirect.  Just bump pointer.
		val = unsafe.Pointer(uintptr(v.val) + field.offset)
	case bigEndian:
		// Direct.  Discard leading bytes.
		val = unsafe.Pointer(uintptr(v.val) << (field.offset * 8))
	default:
		// Direct.  Discard leading bytes.
		val = unsafe.Pointer(uintptr(v.val) >> (field.offset * 8))
	}

	return Value{typ, val, fl}
}

// FieldByIndex returns the nested field corresponding to index.
// It panics if v's Kind is not struct.
func (v Value) FieldByIndex(index []int) Value {
	v.mustBe(Struct)
	for i, x := range index {
		if i > 0 {
			if v.Kind() == Ptr && v.Elem().Kind() == Struct {
				v = v.Elem()
			}
		}
		v = v.Field(x)
	}
	return v
}

// FieldByName returns the struct field with the given name.
// It returns the zero Value if no field was found.
// It panics if v's Kind is not struct.
func (v Value) FieldByName(name string) Value {
	v.mustBe(Struct)
	if f, ok := v.typ.FieldByName(name); ok {
		return v.FieldByIndex(f.Index)
	}
	return Value{}
}

// FieldByNameFunc returns the struct field with a name
// that satisfies the match function.
// It panics if v's Kind is not struct.
// It returns the zero Value if no field was found.
func (v Value) FieldByNameFunc(match func(string) bool) Value {
	v.mustBe(Struct)
	if f, ok := v.typ.FieldByNameFunc(match); ok {
		return v.FieldByIndex(f.Index)
	}
	return Value{}
}

// Float returns v's underlying value, as an float64.
// It panics if v's Kind is not Float32 or Float64
func (v Value) Float() float64 {
	k := v.kind()
	switch k {
	case Float32:
		if v.flag&flagIndir != 0 {
			return float64(*(*float32)(v.val))
		}
		return float64(*(*float32)(unsafe.Pointer(&v.val)))
	case Float64:
		if v.flag&flagIndir != 0 {
			return *(*float64)(v.val)
		}
		return *(*float64)(unsafe.Pointer(&v.val))
	}
	panic(&ValueError{"reflect.Value.Float", k})
}

// Index returns v's i'th element.
// It panics if v's Kind is not Array or Slice or i is out of range.
func (v Value) Index(i int) Value {
	k := v.kind()
	switch k {
	case Array:
		tt := (*arrayType)(unsafe.Pointer(v.typ))
		if i < 0 || i > int(tt.len) {
			panic("reflect: array index out of range")
		}
		typ := toCommonType(tt.elem)
		fl := v.flag & (flagRO | flagIndir | flagAddr) // bits same as overall array
		fl |= flag(typ.Kind()) << flagKindShift
		offset := uintptr(i) * typ.size

		var val unsafe.Pointer
		switch {
		case fl&flagIndir != 0:
			// Indirect.  Just bump pointer.
			val = unsafe.Pointer(uintptr(v.val) + offset)
		case bigEndian:
			// Direct.  Discard leading bytes.
			val = unsafe.Pointer(uintptr(v.val) << (offset * 8))
		default:
			// Direct.  Discard leading bytes.
			val = unsafe.Pointer(uintptr(v.val) >> (offset * 8))
		}
		return Value{typ, val, fl}

	case Slice:
		// Element flag same as Elem of Ptr.
		// Addressable, indirect, possibly read-only.
		fl := flagAddr | flagIndir | v.flag&flagRO
		s := (*SliceHeader)(v.val)
		if i < 0 || i >= s.Len {
			panic("reflect: slice index out of range")
		}
		tt := (*sliceType)(unsafe.Pointer(v.typ))
		typ := toCommonType(tt.elem)
		fl |= flag(typ.Kind()) << flagKindShift
		val := unsafe.Pointer(s.Data + uintptr(i)*typ.size)
		return Value{typ, val, fl}
	}
	panic(&ValueError{"reflect.Value.Index", k})
}

// Int returns v's underlying value, as an int64.
// It panics if v's Kind is not Int, Int8, Int16, Int32, or Int64.
func (v Value) Int() int64 {
	k := v.kind()
	var p unsafe.Pointer
	if v.flag&flagIndir != 0 {
		p = v.val
	} else {
		// The escape analysis is good enough that &v.val
		// does not trigger a heap allocation.
		p = unsafe.Pointer(&v.val)
	}
	switch k {
	case Int:
		return int64(*(*int)(p))
	case Int8:
		return int64(*(*int8)(p))
	case Int16:
		return int64(*(*int16)(p))
	case Int32:
		return int64(*(*int32)(p))
	case Int64:
		return int64(*(*int64)(p))
	}
	panic(&ValueError{"reflect.Value.Int", k})
}

// CanInterface returns true if Interface can be used without panicking.
func (v Value) CanInterface() bool {
	if v.flag == 0 {
		panic(&ValueError{"reflect.Value.CanInterface", Invalid})
	}
	return v.flag&(flagMethod|flagRO) == 0
}

// Interface returns v's value as an interface{}.
// If v is a method obtained by invoking Value.Method
// (as opposed to Type.Method), Interface cannot return an
// interface value, so it panics.
func (v Value) Interface() interface{} {
	return valueInterface(v, true)
}

func valueInterface(v Value, safe bool) interface{} {
	if v.flag == 0 {
		panic(&ValueError{"reflect.Value.Interface", 0})
	}
	if v.flag&flagMethod != 0 {
		panic("reflect.Value.Interface: cannot create interface value for method with bound receiver")
	}

	if safe && v.flag&flagRO != 0 {
		// Do not allow access to unexported values via Interface,
		// because they might be pointers that should not be 
		// writable or methods or function that should not be callable.
		panic("reflect.Value.Interface: cannot return value obtained from unexported field or method")
	}

	k := v.kind()
	if k == Interface {
		// Special case: return the element inside the interface.
		// Empty interface has one layout, all interfaces with
		// methods have a second layout.
		if v.NumMethod() == 0 {
			return *(*interface{})(v.val)
		}
		return *(*interface {
			M()
		})(v.val)
	}

	// Non-interface value.
	var eface emptyInterface
	eface.typ = v.typ.runtimeType()
	eface.word = v.iword()
	return *(*interface{})(unsafe.Pointer(&eface))
}

// InterfaceData returns the interface v's value as a uintptr pair.
// It panics if v's Kind is not Interface.
func (v Value) InterfaceData() [2]uintptr {
	v.mustBe(Interface)
	// We treat this as a read operation, so we allow
	// it even for unexported data, because the caller
	// has to import "unsafe" to turn it into something
	// that can be abused.
	// Interface value is always bigger than a word; assume flagIndir.
	return *(*[2]uintptr)(v.val)
}

// IsNil returns true if v is a nil value.
// It panics if v's Kind is not Chan, Func, Interface, Map, Ptr, or Slice.
func (v Value) IsNil() bool {
	k := v.kind()
	switch k {
	case Chan, Func, Map, Ptr:
		if v.flag&flagMethod != 0 {
			panic("reflect: IsNil of method Value")
		}
		ptr := v.val
		if v.flag&flagIndir != 0 {
			ptr = *(*unsafe.Pointer)(ptr)
		}
		return ptr == nil
	case Interface, Slice:
		// Both interface and slice are nil if first word is 0.
		// Both are always bigger than a word; assume flagIndir.
		return *(*unsafe.Pointer)(v.val) == nil
	}
	panic(&ValueError{"reflect.Value.IsNil", k})
}

// IsValid returns true if v represents a value.
// It returns false if v is the zero Value.
// If IsValid returns false, all other methods except String panic.
// Most functions and methods never return an invalid value.
// If one does, its documentation states the conditions explicitly.
func (v Value) IsValid() bool {
	return v.flag != 0
}

// Kind returns v's Kind.
// If v is the zero Value (IsValid returns false), Kind returns Invalid.
func (v Value) Kind() Kind {
	return v.kind()
}

// Len returns v's length.
// It panics if v's Kind is not Array, Chan, Map, Slice, or String.
func (v Value) Len() int {
	k := v.kind()
	switch k {
	case Array:
		tt := (*arrayType)(unsafe.Pointer(v.typ))
		return int(tt.len)
	case Chan:
		return int(chanlen(*(*iword)(v.iword())))
	case Map:
		return int(maplen(*(*iword)(v.iword())))
	case Slice:
		// Slice is bigger than a word; assume flagIndir.
		return (*SliceHeader)(v.val).Len
	case String:
		// String is bigger than a word; assume flagIndir.
		return (*StringHeader)(v.val).Len
	}
	panic(&ValueError{"reflect.Value.Len", k})
}

// MapIndex returns the value associated with key in the map v.
// It panics if v's Kind is not Map.
// It returns the zero Value if key is not found in the map or if v represents a nil map.
// As in Go, the key's value must be assignable to the map's key type.
func (v Value) MapIndex(key Value) Value {
	v.mustBe(Map)
	tt := (*mapType)(unsafe.Pointer(v.typ))

	// Do not require key to be exported, so that DeepEqual
	// and other programs can use all the keys returned by
	// MapKeys as arguments to MapIndex.  If either the map
	// or the key is unexported, though, the result will be
	// considered unexported.  This is consistent with the
	// behavior for structs, which allow read but not write
	// of unexported fields.
	key = key.assignTo("reflect.Value.MapIndex", toCommonType(tt.key), nil)

	word, ok := mapaccess(v.typ.runtimeType(), *(*iword)(v.iword()), key.iword())
	if !ok {
		return Value{}
	}
	typ := toCommonType(tt.elem)
	fl := (v.flag | key.flag) & flagRO
	if typ.Kind() != Ptr && typ.Kind() != UnsafePointer {
		fl |= flagIndir
	}
	fl |= flag(typ.Kind()) << flagKindShift
	return Value{typ, unsafe.Pointer(word), fl}
}

// MapKeys returns a slice containing all the keys present in the map,
// in unspecified order.
// It panics if v's Kind is not Map.
// It returns an empty slice if v represents a nil map.
func (v Value) MapKeys() []Value {
	v.mustBe(Map)
	tt := (*mapType)(unsafe.Pointer(v.typ))
	keyType := toCommonType(tt.key)

	fl := v.flag & flagRO
	fl |= flag(keyType.Kind()) << flagKindShift
	if keyType.Kind() != Ptr && keyType.Kind() != UnsafePointer {
		fl |= flagIndir
	}

	m := *(*iword)(v.iword())
	mlen := int32(0)
	if m != nil {
		mlen = maplen(m)
	}
	it := mapiterinit(v.typ.runtimeType(), m)
	a := make([]Value, mlen)
	var i int
	for i = 0; i < len(a); i++ {
		keyWord, ok := mapiterkey(it)
		if !ok {
			break
		}
		a[i] = Value{keyType, unsafe.Pointer(keyWord), fl}
		mapiternext(it)
	}
	return a[:i]
}

// Method returns a function value corresponding to v's i'th method.
// The arguments to a Call on the returned function should not include
// a receiver; the returned function will always use v as the receiver.
// Method panics if i is out of range.
func (v Value) Method(i int) Value {
	if v.typ == nil {
		panic(&ValueError{"reflect.Value.Method", Invalid})
	}
	if v.flag&flagMethod != 0 || i < 0 || i >= v.typ.NumMethod() {
		panic("reflect: Method index out of range")
	}
	fl := v.flag & (flagRO | flagAddr | flagIndir)
	fl |= flag(Func) << flagKindShift
	fl |= flag(i)<<flagMethodShift | flagMethod
	return Value{v.typ, v.val, fl}
}

// NumMethod returns the number of methods in the value's method set.
func (v Value) NumMethod() int {
	if v.typ == nil {
		panic(&ValueError{"reflect.Value.NumMethod", Invalid})
	}
	if v.flag&flagMethod != 0 {
		return 0
	}
	return v.typ.NumMethod()
}

// MethodByName returns a function value corresponding to the method
// of v with the given name.
// The arguments to a Call on the returned function should not include
// a receiver; the returned function will always use v as the receiver.
// It returns the zero Value if no method was found.
func (v Value) MethodByName(name string) Value {
	if v.typ == nil {
		panic(&ValueError{"reflect.Value.MethodByName", Invalid})
	}
	if v.flag&flagMethod != 0 {
		return Value{}
	}
	m, ok := v.typ.MethodByName(name)
	if !ok {
		return Value{}
	}
	return v.Method(m.Index)
}

// NumField returns the number of fields in the struct v.
// It panics if v's Kind is not Struct.
func (v Value) NumField() int {
	v.mustBe(Struct)
	tt := (*structType)(unsafe.Pointer(v.typ))
	return len(tt.fields)
}

// OverflowComplex returns true if the complex128 x cannot be represented by v's type.
// It panics if v's Kind is not Complex64 or Complex128.
func (v Value) OverflowComplex(x complex128) bool {
	k := v.kind()
	switch k {
	case Complex64:
		return overflowFloat32(real(x)) || overflowFloat32(imag(x))
	case Complex128:
		return false
	}
	panic(&ValueError{"reflect.Value.OverflowComplex", k})
}

// OverflowFloat returns true if the float64 x cannot be represented by v's type.
// It panics if v's Kind is not Float32 or Float64.
func (v Value) OverflowFloat(x float64) bool {
	k := v.kind()
	switch k {
	case Float32:
		return overflowFloat32(x)
	case Float64:
		return false
	}
	panic(&ValueError{"reflect.Value.OverflowFloat", k})
}

func overflowFloat32(x float64) bool {
	if x < 0 {
		x = -x
	}
	return math.MaxFloat32 <= x && x <= math.MaxFloat64
}

// OverflowInt returns true if the int64 x cannot be represented by v's type.
// It panics if v's Kind is not Int, Int8, int16, Int32, or Int64.
func (v Value) OverflowInt(x int64) bool {
	k := v.kind()
	switch k {
	case Int, Int8, Int16, Int32, Int64:
		bitSize := v.typ.size * 8
		trunc := (x << (64 - bitSize)) >> (64 - bitSize)
		return x != trunc
	}
	panic(&ValueError{"reflect.Value.OverflowInt", k})
}

// OverflowUint returns true if the uint64 x cannot be represented by v's type.
// It panics if v's Kind is not Uint, Uintptr, Uint8, Uint16, Uint32, or Uint64.
func (v Value) OverflowUint(x uint64) bool {
	k := v.kind()
	switch k {
	case Uint, Uintptr, Uint8, Uint16, Uint32, Uint64:
		bitSize := v.typ.size * 8
		trunc := (x << (64 - bitSize)) >> (64 - bitSize)
		return x != trunc
	}
	panic(&ValueError{"reflect.Value.OverflowUint", k})
}

// Pointer returns v's value as a uintptr.
// It returns uintptr instead of unsafe.Pointer so that
// code using reflect cannot obtain unsafe.Pointers
// without importing the unsafe package explicitly.
// It panics if v's Kind is not Chan, Func, Map, Ptr, Slice, or UnsafePointer.
func (v Value) Pointer() uintptr {
	k := v.kind()
	switch k {
	case Chan, Func, Map, Ptr, UnsafePointer:
		if k == Func && v.flag&flagMethod != 0 {
			panic("reflect.Value.Pointer of method Value")
		}
		p := v.val
		if v.flag&flagIndir != 0 {
			p = *(*unsafe.Pointer)(p)
		}
		return uintptr(p)
	case Slice:
		return (*SliceHeader)(v.val).Data
	}
	panic(&ValueError{"reflect.Value.Pointer", k})
}

// Recv receives and returns a value from the channel v.
// It panics if v's Kind is not Chan.
// The receive blocks until a value is ready.
// The boolean value ok is true if the value x corresponds to a send
// on the channel, false if it is a zero value received because the channel is closed.
func (v Value) Recv() (x Value, ok bool) {
	v.mustBe(Chan)
	v.mustBeExported()
	return v.recv(false)
}

// internal recv, possibly non-blocking (nb).
// v is known to be a channel.
func (v Value) recv(nb bool) (val Value, ok bool) {
	tt := (*chanType)(unsafe.Pointer(v.typ))
	if ChanDir(tt.dir)&RecvDir == 0 {
		panic("recv on send-only channel")
	}
	word, selected, ok := chanrecv(v.typ.runtimeType(), *(*iword)(v.iword()), nb)
	if selected {
		typ := toCommonType(tt.elem)
		fl := flag(typ.Kind()) << flagKindShift
		if typ.Kind() != Ptr && typ.Kind() != UnsafePointer {
			fl |= flagIndir
		}
		val = Value{typ, unsafe.Pointer(word), fl}
	}
	return
}

// Send sends x on the channel v.
// It panics if v's kind is not Chan or if x's type is not the same type as v's element type.
// As in Go, x's value must be assignable to the channel's element type.
func (v Value) Send(x Value) {
	v.mustBe(Chan)
	v.mustBeExported()
	v.send(x, false)
}

// internal send, possibly non-blocking.
// v is known to be a channel.
func (v Value) send(x Value, nb bool) (selected bool) {
	tt := (*chanType)(unsafe.Pointer(v.typ))
	if ChanDir(tt.dir)&SendDir == 0 {
		panic("send on recv-only channel")
	}
	x.mustBeExported()
	x = x.assignTo("reflect.Value.Send", toCommonType(tt.elem), nil)
	return chansend(v.typ.runtimeType(), *(*iword)(v.iword()), x.iword(), nb)
}

// Set assigns x to the value v.
// It panics if CanSet returns false.
// As in Go, x's value must be assignable to v's type.
func (v Value) Set(x Value) {
	v.mustBeAssignable()
	x.mustBeExported() // do not let unexported x leak
	var target *interface{}
	if v.kind() == Interface {
		target = (*interface{})(v.val)
	}
	x = x.assignTo("reflect.Set", v.typ, target)
	if x.flag&flagIndir != 0 {
		memmove(v.val, x.val, v.typ.size)
	} else {
		storeIword(v.val, iword(x.val), v.typ.size)
	}
}

// SetBool sets v's underlying value.
// It panics if v's Kind is not Bool or if CanSet() is false.
func (v Value) SetBool(x bool) {
	v.mustBeAssignable()
	v.mustBe(Bool)
	*(*bool)(v.val) = x
}

// SetBytes sets v's underlying value.
// It panics if v's underlying value is not a slice of bytes.
func (v Value) SetBytes(x []byte) {
	v.mustBeAssignable()
	v.mustBe(Slice)
	if v.typ.Elem().Kind() != Uint8 {
		panic("reflect.Value.SetBytes of non-byte slice")
	}
	*(*[]byte)(v.val) = x
}

// SetComplex sets v's underlying value to x.
// It panics if v's Kind is not Complex64 or Complex128, or if CanSet() is false.
func (v Value) SetComplex(x complex128) {
	v.mustBeAssignable()
	switch k := v.kind(); k {
	default:
		panic(&ValueError{"reflect.Value.SetComplex", k})
	case Complex64:
		*(*complex64)(v.val) = complex64(x)
	case Complex128:
		*(*complex128)(v.val) = x
	}
}

// SetFloat sets v's underlying value to x.
// It panics if v's Kind is not Float32 or Float64, or if CanSet() is false.
func (v Value) SetFloat(x float64) {
	v.mustBeAssignable()
	switch k := v.kind(); k {
	default:
		panic(&ValueError{"reflect.Value.SetFloat", k})
	case Float32:
		*(*float32)(v.val) = float32(x)
	case Float64:
		*(*float64)(v.val) = x
	}
}

// SetInt sets v's underlying value to x.
// It panics if v's Kind is not Int, Int8, Int16, Int32, or Int64, or if CanSet() is false.
func (v Value) SetInt(x int64) {
	v.mustBeAssignable()
	switch k := v.kind(); k {
	default:
		panic(&ValueError{"reflect.Value.SetInt", k})
	case Int:
		*(*int)(v.val) = int(x)
	case Int8:
		*(*int8)(v.val) = int8(x)
	case Int16:
		*(*int16)(v.val) = int16(x)
	case Int32:
		*(*int32)(v.val) = int32(x)
	case Int64:
		*(*int64)(v.val) = x
	}
}

// SetLen sets v's length to n.
// It panics if v's Kind is not Slice.
func (v Value) SetLen(n int) {
	v.mustBeAssignable()
	v.mustBe(Slice)
	s := (*SliceHeader)(v.val)
	if n < 0 || n > int(s.Cap) {
		panic("reflect: slice length out of range in SetLen")
	}
	s.Len = n
}

// SetMapIndex sets the value associated with key in the map v to val.
// It panics if v's Kind is not Map.
// If val is the zero Value, SetMapIndex deletes the key from the map.
// As in Go, key's value must be assignable to the map's key type,
// and val's value must be assignable to the map's value type.
func (v Value) SetMapIndex(key, val Value) {
	v.mustBe(Map)
	v.mustBeExported()
	key.mustBeExported()
	tt := (*mapType)(unsafe.Pointer(v.typ))
	key = key.assignTo("reflect.Value.SetMapIndex", toCommonType(tt.key), nil)
	if val.typ != nil {
		val.mustBeExported()
		val = val.assignTo("reflect.Value.SetMapIndex", toCommonType(tt.elem), nil)
	}
	mapassign(v.typ.runtimeType(), *(*iword)(v.iword()), key.iword(), val.iword(), val.typ != nil)
}

// SetUint sets v's underlying value to x.
// It panics if v's Kind is not Uint, Uintptr, Uint8, Uint16, Uint32, or Uint64, or if CanSet() is false.
func (v Value) SetUint(x uint64) {
	v.mustBeAssignable()
	switch k := v.kind(); k {
	default:
		panic(&ValueError{"reflect.Value.SetUint", k})
	case Uint:
		*(*uint)(v.val) = uint(x)
	case Uint8:
		*(*uint8)(v.val) = uint8(x)
	case Uint16:
		*(*uint16)(v.val) = uint16(x)
	case Uint32:
		*(*uint32)(v.val) = uint32(x)
	case Uint64:
		*(*uint64)(v.val) = x
	case Uintptr:
		*(*uintptr)(v.val) = uintptr(x)
	}
}

// SetPointer sets the unsafe.Pointer value v to x.
// It panics if v's Kind is not UnsafePointer.
func (v Value) SetPointer(x unsafe.Pointer) {
	v.mustBeAssignable()
	v.mustBe(UnsafePointer)
	*(*unsafe.Pointer)(v.val) = x
}

// SetString sets v's underlying value to x.
// It panics if v's Kind is not String or if CanSet() is false.
func (v Value) SetString(x string) {
	v.mustBeAssignable()
	v.mustBe(String)
	*(*string)(v.val) = x
}

// Slice returns a slice of v.
// It panics if v's Kind is not Array or Slice.
func (v Value) Slice(beg, end int) Value {
	var (
		cap  int
		typ  *sliceType
		base unsafe.Pointer
	)
	switch k := v.kind(); k {
	default:
		panic(&ValueError{"reflect.Value.Slice", k})
	case Array:
		if v.flag&flagAddr == 0 {
			panic("reflect.Value.Slice: slice of unaddressable array")
		}
		tt := (*arrayType)(unsafe.Pointer(v.typ))
		cap = int(tt.len)
		typ = (*sliceType)(unsafe.Pointer(toCommonType(tt.slice)))
		base = v.val
	case Slice:
		typ = (*sliceType)(unsafe.Pointer(v.typ))
		s := (*SliceHeader)(v.val)
		base = unsafe.Pointer(s.Data)
		cap = s.Cap

	}
	if beg < 0 || end < beg || end > cap {
		panic("reflect.Value.Slice: slice index out of bounds")
	}

	// Declare slice so that gc can see the base pointer in it.
	var x []byte

	// Reinterpret as *SliceHeader to edit.
	s := (*SliceHeader)(unsafe.Pointer(&x))
	s.Data = uintptr(base) + uintptr(beg)*toCommonType(typ.elem).Size()
	s.Len = end - beg
	s.Cap = end - beg

	fl := v.flag&flagRO | flagIndir | flag(Slice)<<flagKindShift
	return Value{typ.common(), unsafe.Pointer(&x), fl}
}

// String returns the string v's underlying value, as a string.
// String is a special case because of Go's String method convention.
// Unlike the other getters, it does not panic if v's Kind is not String.
// Instead, it returns a string of the form "<T value>" where T is v's type.
func (v Value) String() string {
	switch k := v.kind(); k {
	case Invalid:
		return "<invalid Value>"
	case String:
		return *(*string)(v.val)
	}
	// If you call String on a reflect.Value of other type, it's better to
	// print something than to panic. Useful in debugging.
	return "<" + v.typ.String() + " Value>"
}

// TryRecv attempts to receive a value from the channel v but will not block.
// It panics if v's Kind is not Chan.
// If the receive cannot finish without blocking, x is the zero Value.
// The boolean ok is true if the value x corresponds to a send
// on the channel, false if it is a zero value received because the channel is closed.
func (v Value) TryRecv() (x Value, ok bool) {
	v.mustBe(Chan)
	v.mustBeExported()
	return v.recv(true)
}

// TrySend attempts to send x on the channel v but will not block.
// It panics if v's Kind is not Chan.
// It returns true if the value was sent, false otherwise.
// As in Go, x's value must be assignable to the channel's element type.
func (v Value) TrySend(x Value) bool {
	v.mustBe(Chan)
	v.mustBeExported()
	return v.send(x, true)
}

// Type returns v's type.
func (v Value) Type() Type {
	f := v.flag
	if f == 0 {
		panic(&ValueError{"reflect.Value.Type", Invalid})
	}
	if f&flagMethod == 0 {
		// Easy case
		return v.typ.toType()
	}

	// Method value.
	// v.typ describes the receiver, not the method type.
	i := int(v.flag) >> flagMethodShift
	if v.typ.Kind() == Interface {
		// Method on interface.
		tt := (*interfaceType)(unsafe.Pointer(v.typ))
		if i < 0 || i >= len(tt.methods) {
			panic("reflect: broken Value")
		}
		m := &tt.methods[i]
		return toCommonType(m.typ).toType()
	}
	// Method on concrete type.
	ut := v.typ.uncommon()
	if ut == nil || i < 0 || i >= len(ut.methods) {
		panic("reflect: broken Value")
	}
	m := &ut.methods[i]
	return toCommonType(m.mtyp).toType()
}

// Uint returns v's underlying value, as a uint64.
// It panics if v's Kind is not Uint, Uintptr, Uint8, Uint16, Uint32, or Uint64.
func (v Value) Uint() uint64 {
	k := v.kind()
	var p unsafe.Pointer
	if v.flag&flagIndir != 0 {
		p = v.val
	} else {
		// The escape analysis is good enough that &v.val
		// does not trigger a heap allocation.
		p = unsafe.Pointer(&v.val)
	}
	switch k {
	case Uint:
		return uint64(*(*uint)(p))
	case Uint8:
		return uint64(*(*uint8)(p))
	case Uint16:
		return uint64(*(*uint16)(p))
	case Uint32:
		return uint64(*(*uint32)(p))
	case Uint64:
		return uint64(*(*uint64)(p))
	case Uintptr:
		return uint64(*(*uintptr)(p))
	}
	panic(&ValueError{"reflect.Value.Uint", k})
}

// UnsafeAddr returns a pointer to v's data.
// It is for advanced clients that also import the "unsafe" package.
// It panics if v is not addressable.
func (v Value) UnsafeAddr() uintptr {
	if v.typ == nil {
		panic(&ValueError{"reflect.Value.UnsafeAddr", Invalid})
	}
	if v.flag&flagAddr == 0 {
		panic("reflect.Value.UnsafeAddr of unaddressable value")
	}
	return uintptr(v.val)
}

// StringHeader is the runtime representation of a string.
// It cannot be used safely or portably.
type StringHeader struct {
	Data uintptr
	Len  int
}

// SliceHeader is the runtime representation of a slice.
// It cannot be used safely or portably.
type SliceHeader struct {
	Data uintptr
	Len  int
	Cap  int
}

func typesMustMatch(what string, t1, t2 Type) {
	if t1 != t2 {
		panic(what + ": " + t1.String() + " != " + t2.String())
	}
}

// grow grows the slice s so that it can hold extra more values, allocating
// more capacity if needed. It also returns the old and new slice lengths.
func grow(s Value, extra int) (Value, int, int) {
	i0 := s.Len()
	i1 := i0 + extra
	if i1 < i0 {
		panic("reflect.Append: slice overflow")
	}
	m := s.Cap()
	if i1 <= m {
		return s.Slice(0, i1), i0, i1
	}
	if m == 0 {
		m = extra
	} else {
		for m < i1 {
			if i0 < 1024 {
				m += m
			} else {
				m += m / 4
			}
		}
	}
	t := MakeSlice(s.Type(), i1, m)
	Copy(t, s)
	return t, i0, i1
}

// Append appends the values x to a slice s and returns the resulting slice.
// As in Go, each x's value must be assignable to the slice's element type.
func Append(s Value, x ...Value) Value {
	s.mustBe(Slice)
	s, i0, i1 := grow(s, len(x))
	for i, j := i0, 0; i < i1; i, j = i+1, j+1 {
		s.Index(i).Set(x[j])
	}
	return s
}

// AppendSlice appends a slice t to a slice s and returns the resulting slice.
// The slices s and t must have the same element type.
func AppendSlice(s, t Value) Value {
	s.mustBe(Slice)
	t.mustBe(Slice)
	typesMustMatch("reflect.AppendSlice", s.Type().Elem(), t.Type().Elem())
	s, i0, i1 := grow(s, t.Len())
	Copy(s.Slice(i0, i1), t)
	return s
}

// Copy copies the contents of src into dst until either
// dst has been filled or src has been exhausted.
// It returns the number of elements copied.
// Dst and src each must have kind Slice or Array, and
// dst and src must have the same element type.
func Copy(dst, src Value) int {
	dk := dst.kind()
	if dk != Array && dk != Slice {
		panic(&ValueError{"reflect.Copy", dk})
	}
	if dk == Array {
		dst.mustBeAssignable()
	}
	dst.mustBeExported()

	sk := src.kind()
	if sk != Array && sk != Slice {
		panic(&ValueError{"reflect.Copy", sk})
	}
	src.mustBeExported()

	de := dst.typ.Elem()
	se := src.typ.Elem()
	typesMustMatch("reflect.Copy", de, se)

	n := dst.Len()
	if sn := src.Len(); n > sn {
		n = sn
	}

	// If sk is an in-line array, cannot take its address.
	// Instead, copy element by element.
	if src.flag&flagIndir == 0 {
		for i := 0; i < n; i++ {
			dst.Index(i).Set(src.Index(i))
		}
		return n
	}

	// Copy via memmove.
	var da, sa unsafe.Pointer
	if dk == Array {
		da = dst.val
	} else {
		da = unsafe.Pointer((*SliceHeader)(dst.val).Data)
	}
	if sk == Array {
		sa = src.val
	} else {
		sa = unsafe.Pointer((*SliceHeader)(src.val).Data)
	}
	memmove(da, sa, uintptr(n)*de.Size())
	return n
}

/*
 * constructors
 */

// MakeSlice creates a new zero-initialized slice value
// for the specified slice type, length, and capacity.
func MakeSlice(typ Type, len, cap int) Value {
	if typ.Kind() != Slice {
		panic("reflect.MakeSlice of non-slice type")
	}

	// Declare slice so that gc can see the base pointer in it.
	var x []byte

	// Reinterpret as *SliceHeader to edit.
	s := (*SliceHeader)(unsafe.Pointer(&x))
	s.Data = uintptr(unsafe.NewArray(typ.Elem(), cap))
	s.Len = len
	s.Cap = cap

	return Value{typ.common(), unsafe.Pointer(&x), flagIndir | flag(Slice)<<flagKindShift}
}

// MakeChan creates a new channel with the specified type and buffer size.
func MakeChan(typ Type, buffer int) Value {
	if typ.Kind() != Chan {
		panic("reflect.MakeChan of non-chan type")
	}
	if buffer < 0 {
		panic("reflect.MakeChan: negative buffer size")
	}
	if typ.ChanDir() != BothDir {
		panic("reflect.MakeChan: unidirectional channel type")
	}
	ch := makechan(typ.runtimeType(), uint32(buffer))
	return Value{typ.common(), unsafe.Pointer(ch), flagIndir | (flag(Chan)<<flagKindShift)}
}

// MakeMap creates a new map of the specified type.
func MakeMap(typ Type) Value {
	if typ.Kind() != Map {
		panic("reflect.MakeMap of non-map type")
	}
	m := makemap(typ.runtimeType())
	return Value{typ.common(), unsafe.Pointer(m), flagIndir | (flag(Map)<<flagKindShift)}
}

// Indirect returns the value that v points to.
// If v is a nil pointer, Indirect returns a nil Value.
// If v is not a pointer, Indirect returns v.
func Indirect(v Value) Value {
	if v.Kind() != Ptr {
		return v
	}
	return v.Elem()
}

// ValueOf returns a new Value initialized to the concrete value
// stored in the interface i.  ValueOf(nil) returns the zero Value.
func ValueOf(i interface{}) Value {
	if i == nil {
		return Value{}
	}

	// TODO(rsc): Eliminate this terrible hack.
	// In the call to packValue, eface.typ doesn't escape,
	// and eface.word is an integer.  So it looks like
	// i (= eface) doesn't escape.  But really it does,
	// because eface.word is actually a pointer.
	escapes(i)

	// For an interface value with the noAddr bit set,
	// the representation is identical to an empty interface.
	eface := *(*emptyInterface)(unsafe.Pointer(&i))
	typ := toCommonType(eface.typ)
	fl := flag(typ.Kind()) << flagKindShift
	if typ.Kind() != Ptr && typ.Kind() != UnsafePointer {
		fl |= flagIndir
	}
	return Value{typ, unsafe.Pointer(eface.word), fl}
}

// Zero returns a Value representing a zero value for the specified type.
// The result is different from the zero value of the Value struct,
// which represents no value at all.
// For example, Zero(TypeOf(42)) returns a Value with Kind Int and value 0.
func Zero(typ Type) Value {
	if typ == nil {
		panic("reflect: Zero(nil)")
	}
	t := typ.common()
	fl := flag(t.Kind()) << flagKindShift
	if t.Kind() == Ptr || t.Kind() == UnsafePointer {
		return Value{t, nil, fl}
	}
	return Value{t, unsafe.New(typ), fl | flagIndir}
}

// New returns a Value representing a pointer to a new zero value
// for the specified type.  That is, the returned Value's Type is PtrTo(t).
func New(typ Type) Value {
	if typ == nil {
		panic("reflect: New(nil)")
	}
	ptr := unsafe.New(typ)
	fl := flag(Ptr) << flagKindShift
	return Value{typ.common().ptrTo(), ptr, fl}
}

// assignTo returns a value v that can be assigned directly to typ.
// It panics if v is not assignable to typ.
// For a conversion to an interface type, target is a suggested scratch space to use.
func (v Value) assignTo(context string, dst *commonType, target *interface{}) Value {
	if v.flag&flagMethod != 0 {
		panic(context + ": cannot assign method value to type " + dst.String())
	}

	switch {
	case directlyAssignable(dst, v.typ):
		// Overwrite type so that they match.
		// Same memory layout, so no harm done.
		v.typ = dst
		fl := v.flag & (flagRO | flagAddr | flagIndir)
		fl |= flag(dst.Kind()) << flagKindShift
		return Value{dst, v.val, fl}

	case implements(dst, v.typ):
		if target == nil {
			target = new(interface{})
		}
		x := valueInterface(v, false)
		if dst.NumMethod() == 0 {
			*target = x
		} else {
			ifaceE2I(dst.runtimeType(), x, unsafe.Pointer(target))
		}
		return Value{dst, unsafe.Pointer(target), flagIndir | flag(Interface)<<flagKindShift}
	}

	// Failed.
	panic(context + ": value of type " + v.typ.String() + " is not assignable to type " + dst.String())
}

// implemented in ../pkg/runtime
func chancap(ch iword) int32
func chanclose(ch iword)
func chanlen(ch iword) int32
func chanrecv(t *runtime.Type, ch iword, nb bool) (val iword, selected, received bool)
func chansend(t *runtime.Type, ch iword, val iword, nb bool) bool

func makechan(typ *runtime.Type, size uint32) (ch iword)
func makemap(t *runtime.Type) (m iword)
func mapaccess(t *runtime.Type, m iword, key iword) (val iword, ok bool)
func mapassign(t *runtime.Type, m iword, key, val iword, ok bool)
func mapiterinit(t *runtime.Type, m iword) *byte
func mapiterkey(it *byte) (key iword, ok bool)
func mapiternext(it *byte)
func maplen(m iword) int32

func call(typ *commonType, fnaddr unsafe.Pointer, isInterface bool, isMethod bool, params *unsafe.Pointer, results *unsafe.Pointer)
func ifaceE2I(t *runtime.Type, src interface{}, dst unsafe.Pointer)

// Dummy annotation marking that the value x escapes,
// for use in cases where the reflect code is so clever that
// the compiler cannot follow.
func escapes(x interface{}) {
	if dummy.b {
		dummy.x = x
	}
}

var dummy struct {
	b bool
	x interface{}
}
