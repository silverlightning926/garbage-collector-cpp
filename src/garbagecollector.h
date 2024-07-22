#include <vector>

#include "object.h"

#ifndef GARBAGE_COLLECTOR_H
#define GARBAGE_COLLECTOR_H

class GarbageCollector {
 public:
  ~GarbageCollector();

  Object* allocate();
  Object* allocate(bool isRoot);
  void addRoot(Object* root);
  void markAll();
  void sweep();

  void printObjects() const;
  void printRoots() const;

 private:
  void mark(Object* obj);

  std::vector<Object*> roots;
  std::vector<Object*> objects;
};

#endif