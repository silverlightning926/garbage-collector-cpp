#include <iostream>

#include "garbagecollector.h"

int main() {
  // Instantiating Garbage Collector
  GarbageCollector gc;

  // Creating Roots
  Object* root1 = gc.allocate();
  Object* root2 = gc.allocate();

  gc.addRoot(root1);
  gc.addRoot(root2);

  // Creating Refrences
  Object* refrence1 = gc.allocate();
  Object* refrence2 = gc.allocate();
  Object* refrence3 = gc.allocate();

  // Adding Refrences To Roots
  root1->addReference(refrence1);
  root1->addReference(refrence2);

  root2->addReference(refrence3);

  // Simulating Roots Becoming Unreachable
  refrence1 = nullptr;
  refrence2 = nullptr;
  refrence3 = nullptr;

  // Perform Garbage Collection;
  gc.markAll();
  gc.sweep();

  return 0;
}
