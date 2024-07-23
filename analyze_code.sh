#!/bin/bash

echo "====================================================="
echo "clang-tidy"
echo "====================================================="

if hash clang-tidy 2>/dev/null; then
  clang-tidy ./src/*.cpp --
else
  echo "WARNING: clang-tidy not available."
fi

echo ""
echo "====================================================="
echo "clang-format"
echo "====================================================="

if hash clang-format 2>/dev/null; then
  for f in ./src/*.{cpp,h}; do
    echo "Running clang-format on $f"

    tmp_file=$(mktemp)
    
    clang-format -style=file $f > "$tmp_file"

    echo "Diff for $f:"
    diff -u $f "$tmp_file"

    rm "$tmp_file"
    
    echo ""
  done
else
  echo "WARNING: clang-format not available"
fi

echo "====================================================="
echo "valgrind"
echo "====================================================="

if hash valgrind 2>/dev/null; then
  mkdir -p build
  g++ $(find src -name "*.cpp") -o ./build/main
  valgrind --leak-check=full ./build/main
  rm ./build/main
else
  echo "WARNING: valgrind not available"
fi