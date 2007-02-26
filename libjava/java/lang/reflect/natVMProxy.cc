// natVMProxy.cc -- Implementation of VMProxy methods.

/* Copyright (C) 2006
   Free Software Foundation

   This file is part of libgcj.

This software is copyrighted work licensed under the terms of the
Libgcj License.  Please consult the file "LIBGCJ_LICENSE" for
details.  */

// The idea of behind this code is to utilize libffi's ability to
// create closures to provide a fast "cut-through" way to generate
// proxy classes.  Instead of generating bytecode and then
// interpreting that, we copy the method definitions for each of the
// methods we're supposed to be prxying and generate a libffi closure
// for each one.

#include <config.h>
#include <platform.h>
#include <sysdep/descriptor.h>

#include <limits.h>
#include <string.h>
#include <stddef.h>
#include <stdio.h>

#include <gcj/cni.h>
#include <gcj/javaprims.h>
#include <jvm.h>
#include <jni.h>
#include <java-threads.h>
#include <java-interp.h>
#include <ffi.h>
#include <execution.h>
#include <gcj/method.h>

#include <gnu/gcj/runtime/BootClassLoader.h>
#include <java/lang/Class.h>
#include <java/lang/ClassCastException.h>
#include <java/lang/Error.h>
#include <java/lang/IllegalArgumentException.h>
#include <java/lang/Integer.h>
#include <java/lang/StringBuffer.h>
#include <java/lang/VMClassLoader.h>
#include <java/lang/VMCompiler.h>
#include <java/lang/reflect/InvocationHandler.h>
#include <java/lang/reflect/Method.h>
#include <java/lang/reflect/Proxy$ClassFactory.h>
#include <java/lang/reflect/Proxy$ProxyData.h>
#include <java/lang/reflect/Proxy.h>
#include <java/lang/reflect/UndeclaredThrowableException.h>
#include <java/lang/reflect/VMProxy.h>

#include <java/lang/Byte.h>
#include <java/lang/Short.h>
#include <java/lang/Integer.h>
#include <java/lang/Long.h>
#include <java/lang/Float.h>
#include <java/lang/Double.h>
#include <java/lang/Boolean.h>
#include <java/lang/Character.h>


using namespace java::lang::reflect;
using namespace java::lang;

typedef void (*closure_fun) (ffi_cif*, void*, void**, void*);
static void *ncode (_Jv_Method *self, closure_fun fun, Method *meth);
static void run_proxy (ffi_cif*, void*, void**, void*);

typedef jobject invoke_t (jobject, Proxy *, Method *, JArray< jobject > *);

// True if pc points to a proxy frame.

bool 
_Jv_is_proxy (void *pc)
{
  return pc == UNWRAP_FUNCTION_DESCRIPTOR ((void*)&run_proxy);
}

// Generate a proxy class by using libffi closures for each entry
// point.

jclass
java::lang::reflect::VMProxy::generateProxyClass 
  (ClassLoader *loader, Proxy$ProxyData *d)
{
  // If we're precompiling, generate bytecode and allow VMCompiler to
  // precompile it.
  if (VMCompiler::precompiles ())
    return (new Proxy$ClassFactory(d))->generate(loader);

  jclass klass = new Class ();
  klass->superclass = &Proxy::class$;
  klass->engine = &_Jv_soleIndirectCompiledEngine;
  klass->size_in_bytes = Proxy::class$.size_in_bytes;
  klass->vtable_method_count = -1;

  // Synchronize on the class, so that it is not attempted initialized
  // until we're done.
  JvSynchronize sync (klass);

  // Record the defining loader.  For the bootstrap class loader,
  // we record NULL.
  if (loader != VMClassLoader::bootLoader)
    klass->loader = loader;

  {
    StringBuffer *sb = new StringBuffer();
    sb->append(JvNewStringLatin1 ("$Proxy"));
    sb->append(Integer::toString (d->id));
    klass->name = _Jv_makeUtf8Const (sb->toString());
  }

  // Allocate space for the interfaces.
  klass->interface_count = d->interfaces->length;
  klass->interfaces = (jclass*) _Jv_AllocRawObj (klass->interface_count
						 *sizeof (jclass));
  for (int i = 0; i < klass->interface_count; i++)
    klass->interfaces[i] = elements(d->interfaces)[i];

  size_t count = d->methods->length;

  {
    size_t total_count = count + Proxy::class$.method_count + 1;
    if (total_count >= 65536)
      throw new IllegalArgumentException ();
    // Allocate space for the methods.  This is a worst case
    // estimate.
    klass->methods 
      = (_Jv_Method *) _Jv_AllocRawObj (sizeof (_Jv_Method) 
					* total_count);
  }

  jshort &method_count = klass->method_count;

  // Copy all reachable methods from Proxy.
  for (int i = 0; i < Proxy::class$.method_count; i++)
    {
      if (_Jv_CheckAccess (klass, &Proxy::class$,
			   Proxy::class$.methods[i].accflags))
	{
	  klass->methods[method_count] = Proxy::class$.methods[i];
	  method_count++;
	}
    }

  _Jv_Method *init_method 
    = (_Jv_Linker::search_method_in_class 
       (klass, klass,
	_Jv_makeUtf8Const ("<init>"),
	_Jv_makeUtf8Const ("(Ljava.lang.reflect.InvocationHandler;)V"),
	false));  
  init_method->accflags |= Modifier::PUBLIC;

  // Create the methods for all of the interfaces.
  for (size_t i = 0; i < count; i++)
    {
      _Jv_Method &method = klass->methods[method_count++];
      const _Jv_Method &imethod = *_Jv_FromReflectedMethod (elements(d->methods)[i]);
      // We use a shallow copy of IMETHOD rather than a deep copy;
      // this means that the pointer fields of METHOD point into the
      // interface.  As long as this subclass of Proxy is reachable,
      // the interfaces of which it is a proxy will also be reachable,
      // so this is safe.
      method = imethod;
      method.ncode = ncode (&method, run_proxy, elements(d->methods)[i]);
      method.accflags &= ~Modifier::ABSTRACT;
    }

  _Jv_Linker::layout_vtable_methods (klass);
  _Jv_RegisterInitiatingLoader (klass, klass->loader);

  return klass;
}


// Box things with primitive types.
static inline jobject
box (void *thing, jclass klass, FFI_TYPE type)
{
  jobject o;

  switch (type)
    {
    case FFI_TYPE_VOID:
      return NULL;
      
    case FFI_TYPE_POINTER:
      o = *(jobject*)thing;
      return o;

    default:
      ;
    }

  if (klass == JvPrimClass (byte))
    o = new Byte (*(jbyte*)thing);
  else if (klass == JvPrimClass (short))
    o = new Short (*(jshort*)thing);
  else if (klass == JvPrimClass (int))
    o = new Integer (*(jint*)thing);
  else if (klass == JvPrimClass (long))
    o = new Long (*(jlong*)thing);
  else if (klass == JvPrimClass (float))
    o = new Float (*(jfloat*)thing);
  else if (klass == JvPrimClass (double))
    o = new Double (*(jdouble*)thing);
  else if (klass == JvPrimClass (boolean))
    o = new Boolean (*(jboolean*)thing);
  else if (klass == JvPrimClass (char))
    o = new Character (*(jchar*)thing);
  else
    JvFail ("Bad ffi type in proxy");

  return o;
}  


// Unbox things with primitive types.
static inline void
unbox (jobject o, jclass klass, void *rvalue, FFI_TYPE type)
{
  switch (type)
    {
    case FFI_TYPE_VOID:
      return;
      
    case FFI_TYPE_POINTER:
      _Jv_CheckCast (klass, o);
      *(jobject*)rvalue = o;
      return;

    default:
      ;
    }

  // If the value returned ... is null and the interface method's
  // return type is primitive, then a NullPointerException will be
  // thrown ...
  if (klass == JvPrimClass (byte))
    {
      _Jv_CheckCast (&Byte::class$, o);
      *(jbyte*)rvalue = ((Byte*)o)->byteValue();
    }
  else if (klass == JvPrimClass (short))
    {
      _Jv_CheckCast (&Short::class$, o);
      *(jshort*)rvalue = ((Short*)o)->shortValue();
    }
  else if (klass == JvPrimClass (int))
    {
      _Jv_CheckCast (&Integer::class$, o);
      *(jint*)rvalue = ((Integer*)o)->intValue();
    }
  else if (klass == JvPrimClass (long))
    {
      _Jv_CheckCast (&Long::class$, o);
      *(jlong*)rvalue = ((Long*)o)->longValue();
    }
  else if (klass == JvPrimClass (float))
    {
      _Jv_CheckCast (&Float::class$, o);
      *(jfloat*)rvalue = ((Float*)o)->floatValue();
    }
  else if (klass == JvPrimClass (double))
    {
      _Jv_CheckCast (&Double::class$, o);
      *(jdouble*)rvalue = ((Double*)o)->doubleValue();
    }
  else if (klass == JvPrimClass (boolean))
    {
      _Jv_CheckCast (&Boolean::class$, o);
      *(jboolean*)rvalue = ((Boolean*)o)->booleanValue();
    }
  else if (klass == JvPrimClass (char))
    {
      _Jv_CheckCast (&Character::class$, o);
      *(jchar*)rvalue = ((Character*)o)->charValue();
    }
  else
    JvFail ("Bad ffi type in proxy");
}


// run_proxy is the entry point for all proxy methods.  It boxes up
// all the arguments and then invokes the invocation handler's invoke()
// method.  Exceptions are caught and propagated.

typedef struct {
  ffi_closure  closure;
  ffi_cif   cif;
  Method *meth;
  _Jv_Method *self;
  ffi_type *arg_types[0];
} ncode_closure;

static void
run_proxy (ffi_cif *cif,
	   void *rvalue,
	   void **args,
	   void*user_data)
{
  Proxy *proxy = *(Proxy**)args[0];
  ncode_closure *self = (ncode_closure *) user_data;

  // FRAME_DESC registers this particular invocation as the top-most
  // interpreter frame.  This lets the stack tracing code (for
  // Throwable) print information about the Proxy being run rather
  // than about Proxy.class itself.  FRAME_DESC has a destructor so it
  // cleans up automatically when this proxy invocation returns.
  Thread *thread = Thread::currentThread();
  _Jv_InterpFrame frame_desc (self->self, thread, proxy->getClass());

  InvocationHandler *handler = proxy->h;
  void *poo 
    = _Jv_NewObjectArray (self->meth->parameter_types->length, &Object::class$, NULL);
  JArray<jobject> *argsArray = (JArray<jobject> *) poo;
  jobject *jargs = elements(argsArray);

  // FIXME: It must be possible to use fast interface dispatch here,
  // but I've not quite figured out how to do it.
  invoke_t *invoke
    = (invoke_t *)(_Jv_LookupInterfaceMethod 
		   (handler->getClass (), 
		    _Jv_makeUtf8Const ("invoke"),
		    (_Jv_makeUtf8Const 
		     ("(Ljava.lang.Object;Ljava.lang.reflect.Method;[Ljava.lang.Object;)"
		      "Ljava.lang.Object;"))));

  // Copy and box all the args.
  int index = 1;
  for (int i = 0; i < self->meth->parameter_types->length; i++, index++)
    jargs[i] = box (args[index], elements(self->meth->parameter_types)[i],
		    cif->arg_types[index]->type);
  
  jobject ret;
  try
    {
      ret = invoke (handler, proxy, self->meth, argsArray);
    }
  catch (Throwable *t)
    {
      if (_Jv_IsInstanceOf (t, &RuntimeException::class$)
	  || _Jv_IsInstanceOf (t, &Error::class$))
	throw t;

      Class **throwables = elements (self->meth->exception_types);
      for (int i = 0; i < self->meth->exception_types->length; i++)
	if (_Jv_IsInstanceOf (t, throwables[i]))
	  throw t;

      throw new UndeclaredThrowableException (t);
    }

  unbox (ret, self->meth->return_type, rvalue, cif->rtype->type);
}


// Given a method and a closure function, create libffi CIF and return
// the address of its closure.

static void *
ncode (_Jv_Method *self, closure_fun fun, Method *meth)
{
  using namespace java::lang::reflect;

  jboolean staticp = (self->accflags & Modifier::STATIC) != 0;
  int arg_count = _Jv_count_arguments (self->signature, staticp);

  ncode_closure *closure =
    (ncode_closure*)_Jv_AllocBytes (sizeof (ncode_closure)
				    + arg_count * sizeof (ffi_type*));

  _Jv_init_cif (self->signature,
		arg_count,
		staticp,
		&closure->cif,
		&closure->arg_types[0],
		NULL);
  closure->meth = meth;
  closure->self = self;

  JvAssert ((self->accflags & Modifier::NATIVE) == 0);

  ffi_prep_closure (&closure->closure,
		    &closure->cif, 
		    fun,
		    (void*)closure);

  self->ncode = (void*)closure;
  return self->ncode;
}
