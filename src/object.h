#include <vector>
#ifndef OBJECT_H
#define OBJECT_H

class Object {
 public:
  Object();

  bool marked;
  void addReference(Object* objectPtr);
  std::vector<Object*> refrences;
};

#endif