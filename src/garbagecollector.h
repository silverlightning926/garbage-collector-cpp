#include <vector>

#include "object.h"

#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

class GarbageCollector {
 public:
  ~GarbageCollector();

  Object* allocate();
  void addRoot(Object* root);
  void removeRoot(Object* root);
  void markAll();
  void sweep();

 private:
  void mark(Object* obj);

  std::vector<Object*> roots;
  std::vector<Object*> objects;
};

#endif