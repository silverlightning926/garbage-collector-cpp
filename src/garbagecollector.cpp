#include "garbagecollector.h"

#include <iostream>

#include "object.h"

GarbageCollector::~GarbageCollector() { sweep(); }

Object* GarbageCollector::allocate() {
  std::cout << "Allocating new object" << std::endl;

  Object* obj = new Object;
  objects.push_back(obj);

  return obj;
}

void GarbageCollector::markAll(Object* root) {
  if (root) {
    std::cout << "Marking root object at address: " << root << std::endl;
    mark(root);
  } else {
    std::cout << "Root is null, nothing to mark." << std::endl;
  }
}

void GarbageCollector::sweep() {
  std::cout << "Starting garbage collection sweep." << std::endl;

  for (auto it = objects.begin(); it != objects.end();) {
    std::cout << "Checking object at address: " << *it << std::endl;

    if (!(*it)->marked) {
      std::cout << "Object at address " << *it << " is unmarked. Deleting."
                << std::endl;
      delete *it;
      it = objects.erase(it);
    } else {
      std::cout << "Object at address " << *it << " is marked. Keeping."
                << std::endl;
      (*it)->marked = false;
      ++it;
    }
  }

  std::cout << "Garbage collection sweep completed." << std::endl;
}

void GarbageCollector::mark(Object* obj) {
  if (!obj) return;
  if (obj->marked) return;

  obj->marked = true;
  std::cout << "Marked object at address: " << obj << std::endl;

  for (Object* ref : obj->refrences) {
    std::cout << "Marking reference from object at address " << obj
              << " to object at address " << ref << std::endl;
    mark(ref);
  }
}