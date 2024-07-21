#include "object.h"

Object::Object() { marked = false; }

void Object::addReference(Object* objref) { refrences.push_back(objref); }