#include "object.h"

#include <iostream>

Object::Object() {
  std::cout << "Object created & allocated at address: " << this << std::endl;
  marked = false;
}

void Object::addReference(Object* objPtr) {
  std::cout << "Added reference from object at address " << this
            << " to object at address " << objPtr << std::endl;
  refrences.push_back(objPtr);
}