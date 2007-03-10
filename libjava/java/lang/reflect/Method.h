
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_lang_reflect_Method__
#define __java_lang_reflect_Method__

#pragma interface

#include <java/lang/reflect/AccessibleObject.h>
#include <gcj/array.h>


jmethodID _Jv_FromReflectedMethod (java::lang::reflect::Method *);
jobject _Jv_JNI_ToReflectedMethod (_Jv_JNIEnv *, jclass, jmethodID, jboolean);

class java::lang::reflect::Method : public ::java::lang::reflect::AccessibleObject
{

  Method();
public:
  ::java::lang::Class * getDeclaringClass();
  ::java::lang::String * getName();
private:
  jint getModifiersInternal();
public:
  jint getModifiers();
  jboolean isBridge();
  jboolean isSynthetic();
  jboolean isVarArgs();
  ::java::lang::Class * getReturnType();
  JArray< ::java::lang::Class * > * getParameterTypes();
  JArray< ::java::lang::Class * > * getExceptionTypes();
  jboolean equals(::java::lang::Object *);
  jint hashCode();
  ::java::lang::String * toString();
  ::java::lang::String * toGenericString();
  ::java::lang::Object * invoke(::java::lang::Object *, JArray< ::java::lang::Object * > *);
  JArray< ::java::lang::reflect::TypeVariable * > * getTypeParameters();
private:
  ::java::lang::String * getSignature();
public:
  JArray< ::java::lang::reflect::Type * > * getGenericExceptionTypes();
  JArray< ::java::lang::reflect::Type * > * getGenericParameterTypes();
  ::java::lang::reflect::Type * getGenericReturnType();
  ::java::lang::Object * getDefaultValue();
  ::java::lang::annotation::Annotation * getAnnotation(::java::lang::Class *);
  JArray< ::java::lang::annotation::Annotation * > * getDeclaredAnnotations();
  JArray< JArray< ::java::lang::annotation::Annotation * > * > * getParameterAnnotations();
private:
  JArray< ::java::lang::annotation::Annotation * > * getDeclaredAnnotationsInternal();
  JArray< JArray< ::java::lang::annotation::Annotation * > * > * getParameterAnnotationsInternal();
  void getType();
public: // actually package-private
  static void appendClassName(::java::lang::StringBuffer *, ::java::lang::Class *);
  static const jint METHOD_MODIFIERS = 3391;
private:
  ::java::lang::Class * __attribute__((aligned(__alignof__( ::java::lang::reflect::AccessibleObject)))) declaringClass;
public: // actually package-private
  JArray< ::java::lang::Class * > * exception_types;
private:
  ::java::lang::String * name;
public: // actually package-private
  JArray< ::java::lang::Class * > * parameter_types;
  ::java::lang::Class * return_type;
private:
  jint offset;
public:
  static ::java::lang::Class class$;

  friend jmethodID (::_Jv_FromReflectedMethod) (java::lang::reflect::Method *);
  friend jobject (::_Jv_JNI_ToReflectedMethod) (_Jv_JNIEnv *, jclass, jmethodID, jboolean);
  friend class java::lang::Class;
  friend class java::io::ObjectInputStream;
};

#endif // __java_lang_reflect_Method__
