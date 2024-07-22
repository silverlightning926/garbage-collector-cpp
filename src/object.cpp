#include "object.h"

Object::Object() { marked = false; }

void Object::addReference(Object* objPtr) { refrences.push_back(objPtr); }