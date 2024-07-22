#include <iostream>

#include "garbagecollector.h"

int main() {
  // Instantiating Garbage Collector
  GarbageCollector gc;

  // Allocation Of Root Object
  Object* root = gc.allocate();

  // Allocation Of Child Refrences
  Object* refrence1 = gc.allocate();
  Object* refrence2 = gc.allocate();

  // Set Up Refrences
  root->addReference(refrence1);
  root->addReference(refrence2);

  // Simulate some objects becoming unreachable
  refrence1 = nullptr;
  refrence2 = nullptr;

  // Preform Garbage Collection
  gc.markAll(root);
  gc.sweep();

  return 0;
}
