#!/bin/bash

# Create the build directory if it doesn't exist
mkdir -p build

echo "====================================================="
echo "Building executable with g++"
echo "====================================================="
# Build the source code
g++ $(find src -name "*.cpp") -o ./build/main

echo ""
echo "====================================================="
echo "Running Built Executable:"
echo "====================================================="
# Run the executable
./build/main

echo ""
echo "====================================================="
echo "Removing Executable"
echo "====================================================="
# Delete the executable
rm build/main