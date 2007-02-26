
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_w3c_dom_CDATASection__
#define __org_w3c_dom_CDATASection__

#pragma interface

#include <java/lang/Object.h>
extern "Java"
{
  namespace org
  {
    namespace w3c
    {
      namespace dom
      {
          class CDATASection;
          class Document;
          class NamedNodeMap;
          class Node;
          class NodeList;
          class Text;
          class UserDataHandler;
      }
    }
  }
}

class org::w3c::dom::CDATASection : public ::java::lang::Object
{

public:
  virtual ::org::w3c::dom::Text * splitText(jint) = 0;
  virtual jboolean isElementContentWhitespace() = 0;
  virtual ::java::lang::String * getWholeText() = 0;
  virtual ::org::w3c::dom::Text * replaceWholeText(::java::lang::String *) = 0;
  virtual ::java::lang::String * getData() = 0;
  virtual void setData(::java::lang::String *) = 0;
  virtual jint getLength() = 0;
  virtual ::java::lang::String * substringData(jint, jint) = 0;
  virtual void appendData(::java::lang::String *) = 0;
  virtual void insertData(jint, ::java::lang::String *) = 0;
  virtual void deleteData(jint, jint) = 0;
  virtual void replaceData(jint, jint, ::java::lang::String *) = 0;
  virtual ::java::lang::String * getNodeName() = 0;
  virtual ::java::lang::String * getNodeValue() = 0;
  virtual void setNodeValue(::java::lang::String *) = 0;
  virtual jshort getNodeType() = 0;
  virtual ::org::w3c::dom::Node * getParentNode() = 0;
  virtual ::org::w3c::dom::NodeList * getChildNodes() = 0;
  virtual ::org::w3c::dom::Node * getFirstChild() = 0;
  virtual ::org::w3c::dom::Node * getLastChild() = 0;
  virtual ::org::w3c::dom::Node * getPreviousSibling() = 0;
  virtual ::org::w3c::dom::Node * getNextSibling() = 0;
  virtual ::org::w3c::dom::NamedNodeMap * getAttributes() = 0;
  virtual ::org::w3c::dom::Document * getOwnerDocument() = 0;
  virtual ::org::w3c::dom::Node * insertBefore(::org::w3c::dom::Node *, ::org::w3c::dom::Node *) = 0;
  virtual ::org::w3c::dom::Node * replaceChild(::org::w3c::dom::Node *, ::org::w3c::dom::Node *) = 0;
  virtual ::org::w3c::dom::Node * removeChild(::org::w3c::dom::Node *) = 0;
  virtual ::org::w3c::dom::Node * appendChild(::org::w3c::dom::Node *) = 0;
  virtual jboolean hasChildNodes() = 0;
  virtual ::org::w3c::dom::Node * cloneNode(jboolean) = 0;
  virtual void normalize() = 0;
  virtual jboolean isSupported(::java::lang::String *, ::java::lang::String *) = 0;
  virtual ::java::lang::String * getNamespaceURI() = 0;
  virtual ::java::lang::String * getPrefix() = 0;
  virtual void setPrefix(::java::lang::String *) = 0;
  virtual ::java::lang::String * getLocalName() = 0;
  virtual jboolean hasAttributes() = 0;
  virtual ::java::lang::String * getBaseURI() = 0;
  virtual jshort compareDocumentPosition(::org::w3c::dom::Node *) = 0;
  virtual ::java::lang::String * getTextContent() = 0;
  virtual void setTextContent(::java::lang::String *) = 0;
  virtual jboolean isSameNode(::org::w3c::dom::Node *) = 0;
  virtual ::java::lang::String * lookupPrefix(::java::lang::String *) = 0;
  virtual jboolean isDefaultNamespace(::java::lang::String *) = 0;
  virtual ::java::lang::String * lookupNamespaceURI(::java::lang::String *) = 0;
  virtual jboolean isEqualNode(::org::w3c::dom::Node *) = 0;
  virtual ::java::lang::Object * getFeature(::java::lang::String *, ::java::lang::String *) = 0;
  virtual ::java::lang::Object * setUserData(::java::lang::String *, ::java::lang::Object *, ::org::w3c::dom::UserDataHandler *) = 0;
  virtual ::java::lang::Object * getUserData(::java::lang::String *) = 0;
  static ::java::lang::Class class$;
} __attribute__ ((java_interface));

#endif // __org_w3c_dom_CDATASection__
