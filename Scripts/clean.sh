#!/bin/bash

# Remove executable files.
find ../src/cpp -type f -not -iname "*.*" -exec rm '{}' \;

# Remove build files.
rm -f ./build/build.txt
rm -f ./build/index.html