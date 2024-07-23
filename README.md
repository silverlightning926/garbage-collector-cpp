# Garbage Collector in C++

---

![C++](https://img.shields.io/badge/C++-%2300599C.svg?style=flat&logo=c%2B%2B&logoColor=white) ![Shell Script](https://img.shields.io/badge/Shell_Script-%23121011.svg?style=flat&logo=gnu-bash&logoColor=white)

---

![Build And Run Workflow](https://github.com/silverlightning926/garbage-collector-cpp/actions/workflows/build-and-run.yaml/badge.svg) ![Analyze Code](https://github.com/silverlightning926/garbage-collector-cpp/actions/workflows/analyze-code.yaml/badge.svg)

---

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Garbage Collector in C++](#garbage-collector-in-c)
  - [Introduction](#introduction)
  - [Current Status](#current-status)
  - [Getting Started](#getting-started)
  - [Logic](#logic)
  - [Upcoming Features](#upcoming-features)
  - [License](#license)

<!-- /code_chunk_output -->

## Introduction

Garbage collection is a form of automatic memory management used by a program or programming language. The garbage collector, or just collector, attempts to reclaim garbage, or memory occupied by objects that are no longer in use by the program.

Therefore, to understand the concept of garbage collection, I have implemented a simple garbage collector in C++.

## Current Status

The project is currently in the development phase. ⚠️

## Getting Started

To get started with the project, follow the steps below:

1. Make sure you have installed the following in your environment:

   - [GCC](https://gcc.gnu.org/)
   - [Clang](https://clang.llvm.org/)
   - [Valgrind](https://www.valgrind.org/)
   - [Git](https://git-scm.com/)
   - [Bash](https://www.gnu.org/software/bash/)

2. Clone the repository:

```bash
git clone https://github.com/silverlightning926/garbage-collector-cpp.git
```

3. Run The Code:

```bash
bash build_and_run.sh
```

4. Analyze The Code Using `clang-tidy`, `clang-format`, and `valgrind`:

```bash
bash analyze_code.sh
```

## Logic

The logic of the garbage collector is mostly stored in the [GarbageCollector](src/garbage_collector.h) class.

The `GarbageCollector` class allows the user to allocate memory to a new object using the `allocate` method. The `allocate` method returns a pointer to the allocated memory. The user can then use this pointer to store the object.

The class periodically does what's called a "mark and sweep" operation. The `mark` method marks all the objects that are still in use. The `sweep` method then sweeps through the memory and deallocates the memory that is not in use (not marked by the `mark` method).

Currently, the GC marks and sweeps at a set point in the code, however, I plan on implementing a more dynamic approach in the future.

## Upcoming Features

- Implement dynamic scheduling for the mark and sweep operation.
- Implement short-lived and long-lived object separation.
- Implement better logging and printing of actions.
- Add Profiling and Benchmarking.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
