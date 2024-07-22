#include "garbagecollector.h"

GarbageCollector::~GarbageCollector() { sweep(); }

Object* GarbageCollector::allocate() {
  Object* obj = new Object;
  objects.push_back(obj);
  return obj;
}

void GarbageCollector::markAll(Object* root) { mark(root); }

void GarbageCollector::sweep() {
  for (std::vector<Object*>::iterator it = objects.begin();
       it != objects.end();) {
    if (!(*it)->marked) {
      delete *it;
      it = objects.erase(it);
    } else {
      (*it)->marked = false;
      ++it;
    }
  }
}

void GarbageCollector::mark(Object* obj) {
  if (!obj || !obj->marked) return;

  obj->marked = true;

  for (Object* ref : obj->refrences) {
    mark(ref);
  }
};