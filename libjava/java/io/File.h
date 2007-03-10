
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_io_File__
#define __java_io_File__

#pragma interface

#include <java/lang/Object.h>
#include <gcj/array.h>

extern "Java"
{
  namespace java
  {
    namespace net
    {
        class URI;
        class URL;
    }
  }
}

class java::io::File : public ::java::lang::Object
{

  jlong attr(jint);
  jboolean _access(jint);
  jboolean _stat(jint);
  static void init_native();
public:
  virtual jboolean canRead();
  virtual jboolean canWrite();
private:
  jboolean performCreate();
public:
  virtual jboolean createNewFile();
private:
  jboolean performDelete();
public:
  virtual jboolean delete$();
  virtual jboolean equals(::java::lang::Object *);
private:
  jboolean internalExists();
public:
  virtual jboolean exists();
  File(::java::lang::String *);
private:
  ::java::lang::String * normalizePath(::java::lang::String *);
public:
  File(::java::lang::String *, ::java::lang::String *);
  File(::java::io::File *, ::java::lang::String *);
  File(::java::net::URI *);
  virtual ::java::lang::String * getAbsolutePath();
  virtual ::java::io::File * getAbsoluteFile();
  virtual ::java::lang::String * getCanonicalPath();
  virtual ::java::io::File * getCanonicalFile();
  virtual ::java::lang::String * getName();
  virtual ::java::lang::String * getParent();
  virtual ::java::io::File * getParentFile();
  virtual ::java::lang::String * getPath();
  virtual jint hashCode();
  virtual jboolean isAbsolute();
private:
  jboolean internalIsDirectory();
public:
  virtual jboolean isDirectory();
  virtual jboolean isFile();
  virtual jboolean isHidden();
  virtual jlong lastModified();
  virtual jlong length();
private:
  JArray< ::java::lang::Object * > * performList(::java::io::FilenameFilter *, ::java::io::FileFilter *, ::java::lang::Class *);
public:
  virtual JArray< ::java::lang::String * > * list(::java::io::FilenameFilter *);
  virtual JArray< ::java::lang::String * > * list();
  virtual JArray< ::java::io::File * > * listFiles();
  virtual JArray< ::java::io::File * > * listFiles(::java::io::FilenameFilter *);
  virtual JArray< ::java::io::File * > * listFiles(::java::io::FileFilter *);
  virtual ::java::lang::String * toString();
  virtual ::java::net::URI * toURI();
  virtual ::java::net::URL * toURL();
private:
  jboolean performMkdir();
public:
  virtual jboolean mkdir();
private:
  static jboolean mkdirs(::java::io::File *);
public:
  virtual jboolean mkdirs();
private:
  static ::java::lang::String * nextValue();
public:
  static ::java::io::File * createTempFile(::java::lang::String *, ::java::lang::String *, ::java::io::File *);
private:
  jboolean performSetReadOnly();
public:
  virtual jboolean setReadOnly();
private:
  static JArray< ::java::io::File * > * performListRoots();
public:
  static JArray< ::java::io::File * > * listRoots();
  static ::java::io::File * createTempFile(::java::lang::String *, ::java::lang::String *);
  virtual jint compareTo(::java::io::File *);
  virtual jint compareTo(::java::lang::Object *);
private:
  jboolean performRenameTo(::java::io::File *);
public:
  virtual jboolean renameTo(::java::io::File *);
private:
  jboolean performSetLastModified(jlong);
public:
  virtual jboolean setLastModified(jlong);
private:
  void checkWrite();
  void checkRead();
public:
  virtual void deleteOnExit();
private:
  void writeObject(::java::io::ObjectOutputStream *);
  void readObject(::java::io::ObjectInputStream *);
  static const jlong serialVersionUID = 301077366599181567LL;
  static const jint READ = 0;
  static const jint WRITE = 1;
  static const jint EXISTS = 2;
  static const jint DIRECTORY = 0;
  static const jint ISFILE = 1;
  static const jint ISHIDDEN = 2;
  static const jint MODIFIED = 0;
  static const jint LENGTH = 1;
public:
  static ::java::lang::String * separator;
private:
  static ::java::lang::String * dupSeparator;
public:
  static jchar separatorChar;
  static ::java::lang::String * pathSeparator;
  static jchar pathSeparatorChar;
public: // actually package-private
  static ::java::lang::String * tmpdir;
  static jint maxPathLen;
  static jboolean caseSensitive;
private:
  ::java::lang::String * __attribute__((aligned(__alignof__( ::java::lang::Object)))) path;
  static jlong counter;
public:
  static ::java::lang::Class class$;
};

#endif // __java_io_File__
