#include "object.h"

#include <iostream>

Object::Object() {
  std::cout << "Object at address: " << this << " allocated." << std::endl;
  marked = false;
}

Object::~Object() {
  std::cout << "Object at address: " << this << " deallocated." << std::endl;
}

void Object::addReference(Object* objPtr) {
  std::cout << "Adding Object Refrence: " << objPtr << " to Object: " << this
            << std::endl;
  refrences.push_back(objPtr);
}