#include <vector>

#include "object.h"

#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

class GarbageCollector {
 public:
  ~GarbageCollector();

  Object* allocate();
  void markAll(Object* root);
  void sweep();

 private:
  void mark(Object* obj);
  std::vector<Object*> objects;
};

#endif