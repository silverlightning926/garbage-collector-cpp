#include "garbagecollector.h"

#include <iostream>

GarbageCollector::~GarbageCollector() { sweep(); }

Object* GarbageCollector::allocate() {
  std::cout << "Allocating new object." << std::endl;

  Object* obj = new Object;
  objects.push_back(obj);

  return obj;
}

void GarbageCollector::markAll() {
  std::cout << "Marking all objects." << std::endl;

  for (Object* root : roots) {
    std::cout << "Marking root object: " << root << std::endl;
    mark(root);
  }
}

void GarbageCollector::sweep() {
  std::cout << "Performing Sweep on all objects." << std::endl;

  for (std::vector<Object*>::iterator it = objects.begin();
       it != objects.end();) {
    std::cout << "Checking " << *it << " for deletion." << std::endl;

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
}

void GarbageCollector::mark(Object* obj) {
  if (!obj || obj->marked) return;

  std::cout << "Marking " << obj << " as not to be deleted." << std::endl;

  obj->marked = true;

  std::cout << "Marking Refrences of " << obj << " as not to be deleted."
            << std::endl;

  for (Object* ref : obj->refrences) {
    std::cout << "Marking Refrence of " << obj << ": " << ref
              << " as not to be deleted." << std::endl;
    mark(ref);
  }
};
