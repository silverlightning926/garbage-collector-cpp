#!/bin/bash

echo "====================================================="
echo "clang-tidy"
echo "====================================================="

if hash clang-tidy 2>/dev/null; then
  clang-tidy ./src/*.cpp -- -std=c++14
else
  echo "WARNING: clang-tidy not available."
fi

echo ""
echo "====================================================="
echo "clang-format"
echo "====================================================="

if hash clang-format 2>/dev/null; then
  for f in ./src/*.cpp; do
    echo "Running clang-format on $f"
    clang-format $f | diff $f -
  done
else
  echo "WARNING: clang-format not available"
fi