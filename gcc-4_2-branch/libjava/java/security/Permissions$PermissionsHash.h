
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __java_security_Permissions$PermissionsHash__
#define __java_security_Permissions$PermissionsHash__

#pragma interface

#include <java/security/PermissionCollection.h>
extern "Java"
{
  namespace java
  {
    namespace security
    {
        class Permission;
        class Permissions$PermissionsHash;
    }
  }
}

class java::security::Permissions$PermissionsHash : public ::java::security::PermissionCollection
{

  Permissions$PermissionsHash();
public:
  void add(::java::security::Permission *);
  jboolean implies(::java::security::Permission *);
  ::java::util::Enumeration * elements();
public: // actually package-private
  Permissions$PermissionsHash(::java::security::Permissions$PermissionsHash *);
private:
  static const jlong serialVersionUID = -8491988220802933440LL;
  ::java::util::Hashtable * __attribute__((aligned(__alignof__( ::java::security::PermissionCollection)))) perms;
public:
  static ::java::lang::Class class$;
};

#endif // __java_security_Permissions$PermissionsHash__
