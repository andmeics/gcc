
// DO NOT EDIT THIS FILE - it is machine generated -*- c++ -*-

#ifndef __org_w3c_dom_html2_HTMLTableElement__
#define __org_w3c_dom_html2_HTMLTableElement__

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
          class Attr;
          class Document;
          class NamedNodeMap;
          class Node;
          class NodeList;
          class TypeInfo;
          class UserDataHandler;
        namespace html2
        {
            class HTMLCollection;
            class HTMLElement;
            class HTMLTableCaptionElement;
            class HTMLTableElement;
            class HTMLTableSectionElement;
        }
      }
    }
  }
}

class org::w3c::dom::html2::HTMLTableElement : public ::java::lang::Object
{

public:
  virtual ::org::w3c::dom::html2::HTMLTableCaptionElement * getCaption() = 0;
  virtual void setCaption(::org::w3c::dom::html2::HTMLTableCaptionElement *) = 0;
  virtual ::org::w3c::dom::html2::HTMLTableSectionElement * getTHead() = 0;
  virtual void setTHead(::org::w3c::dom::html2::HTMLTableSectionElement *) = 0;
  virtual ::org::w3c::dom::html2::HTMLTableSectionElement * getTFoot() = 0;
  virtual void setTFoot(::org::w3c::dom::html2::HTMLTableSectionElement *) = 0;
  virtual ::org::w3c::dom::html2::HTMLCollection * getRows() = 0;
  virtual ::org::w3c::dom::html2::HTMLCollection * getTBodies() = 0;
  virtual ::java::lang::String * getAlign() = 0;
  virtual void setAlign(::java::lang::String *) = 0;
  virtual ::java::lang::String * getBgColor() = 0;
  virtual void setBgColor(::java::lang::String *) = 0;
  virtual ::java::lang::String * getBorder() = 0;
  virtual void setBorder(::java::lang::String *) = 0;
  virtual ::java::lang::String * getCellPadding() = 0;
  virtual void setCellPadding(::java::lang::String *) = 0;
  virtual ::java::lang::String * getCellSpacing() = 0;
  virtual void setCellSpacing(::java::lang::String *) = 0;
  virtual ::java::lang::String * getFrame() = 0;
  virtual void setFrame(::java::lang::String *) = 0;
  virtual ::java::lang::String * getRules() = 0;
  virtual void setRules(::java::lang::String *) = 0;
  virtual ::java::lang::String * getSummary() = 0;
  virtual void setSummary(::java::lang::String *) = 0;
  virtual ::java::lang::String * getWidth() = 0;
  virtual void setWidth(::java::lang::String *) = 0;
  virtual ::org::w3c::dom::html2::HTMLElement * createTHead() = 0;
  virtual void deleteTHead() = 0;
  virtual ::org::w3c::dom::html2::HTMLElement * createTFoot() = 0;
  virtual void deleteTFoot() = 0;
  virtual ::org::w3c::dom::html2::HTMLElement * createCaption() = 0;
  virtual void deleteCaption() = 0;
  virtual ::org::w3c::dom::html2::HTMLElement * insertRow(jint) = 0;
  virtual void deleteRow(jint) = 0;
  virtual ::java::lang::String * getId() = 0;
  virtual void setId(::java::lang::String *) = 0;
  virtual ::java::lang::String * getTitle() = 0;
  virtual void setTitle(::java::lang::String *) = 0;
  virtual ::java::lang::String * getLang() = 0;
  virtual void setLang(::java::lang::String *) = 0;
  virtual ::java::lang::String * getDir() = 0;
  virtual void setDir(::java::lang::String *) = 0;
  virtual ::java::lang::String * getClassName() = 0;
  virtual void setClassName(::java::lang::String *) = 0;
  virtual ::java::lang::String * getTagName() = 0;
  virtual ::java::lang::String * getAttribute(::java::lang::String *) = 0;
  virtual void setAttribute(::java::lang::String *, ::java::lang::String *) = 0;
  virtual void removeAttribute(::java::lang::String *) = 0;
  virtual ::org::w3c::dom::Attr * getAttributeNode(::java::lang::String *) = 0;
  virtual ::org::w3c::dom::Attr * setAttributeNode(::org::w3c::dom::Attr *) = 0;
  virtual ::org::w3c::dom::Attr * removeAttributeNode(::org::w3c::dom::Attr *) = 0;
  virtual ::org::w3c::dom::NodeList * getElementsByTagName(::java::lang::String *) = 0;
  virtual ::java::lang::String * getAttributeNS(::java::lang::String *, ::java::lang::String *) = 0;
  virtual void setAttributeNS(::java::lang::String *, ::java::lang::String *, ::java::lang::String *) = 0;
  virtual void removeAttributeNS(::java::lang::String *, ::java::lang::String *) = 0;
  virtual ::org::w3c::dom::Attr * getAttributeNodeNS(::java::lang::String *, ::java::lang::String *) = 0;
  virtual ::org::w3c::dom::Attr * setAttributeNodeNS(::org::w3c::dom::Attr *) = 0;
  virtual ::org::w3c::dom::NodeList * getElementsByTagNameNS(::java::lang::String *, ::java::lang::String *) = 0;
  virtual jboolean hasAttribute(::java::lang::String *) = 0;
  virtual jboolean hasAttributeNS(::java::lang::String *, ::java::lang::String *) = 0;
  virtual ::org::w3c::dom::TypeInfo * getSchemaTypeInfo() = 0;
  virtual void setIdAttribute(::java::lang::String *, jboolean) = 0;
  virtual void setIdAttributeNS(::java::lang::String *, ::java::lang::String *, jboolean) = 0;
  virtual void setIdAttributeNode(::org::w3c::dom::Attr *, jboolean) = 0;
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

#endif // __org_w3c_dom_html2_HTMLTableElement__
