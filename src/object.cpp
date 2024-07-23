#include "object.h"

#include <iostream>

Object::Object() {
  std::cout << "Object at address: " << this << " allocated." << std::endl;
  marked = false;
}

Object::~Object() {
  std::cout << "Object at address: " << this << " deallocated." << std::endl;
}

void Object::addReference(Object* objectPtr) {
  std::cout << "Adding Object Refrence: " << objectPtr << " to Object: " << this
            << std::endl;
  references.push_back(objectPtr);
}