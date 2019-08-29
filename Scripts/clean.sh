#!/bin/bash

# Remove executable files.
find ../src/cpp -type f -not -iname "*.*" -exec rm '{}' \;

# Remove build files.
rm -f ../docs/build.txt
rm -f ../docs/index.html