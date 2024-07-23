#include <iostream>

#include "garbagecollector.h"

int main() {
  // Instantiating Garbage Collector
  std::cout << "Instantiating Garbage Collector." << std::endl;
  GarbageCollector gc;
  std::cout << std::endl;

  // Creating Roots
  std::cout << "Creating Roots." << std::endl;
  Object* root1 = gc.allocate(true);
  Object* root2 = gc.allocate(true);
  std::cout << std::endl;

  // Creating Refrences
  std::cout << "Creating Refrences." << std::endl;
  Object* refrence1 = gc.allocate();
  Object* refrence2 = gc.allocate();
  Object* refrence3 = gc.allocate();
  std::cout << std::endl;

  // Adding Refrences To Roots
  std::cout << "Adding Refrences To Roots" << std::endl;
  root1->addReference(refrence1);
  root1->addReference(refrence2);

  root2->addReference(refrence3);
  std::cout << std::endl;

  // Simulating Roots Becoming Unreachable
  std::cout << "Simulating Roots Becoming Unreachable" << std::endl;
  refrence1 = nullptr;
  refrence2 = nullptr;
  refrence3 = nullptr;
  std::cout << std::endl;

  // Perform Garbage Collection;
  std::cout << "Preforming Garbage Collection" << std::endl;
  gc.markAll();
  gc.sweep();
  std::cout << std::endl;

  // Print Current State
  std::cout << "Printing Garbage Collector State" << std::endl;
  gc.printRoots();
  gc.printObjects();
  std::cout << std::endl;

  return 0;
}
