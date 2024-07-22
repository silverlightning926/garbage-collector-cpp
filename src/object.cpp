#include "object.h"

#include <iostream>

Object::Object() {
  std::cout << "Object allocated at address: " << this << std::endl;
  marked = false;
}

void Object::addReference(Object* objPtr) {
  std::cout << "Adding Refrence to (" << objPtr << ") to Object at (" << this
            << ")." << std::endl;
  refrences.push_back(objPtr);
}