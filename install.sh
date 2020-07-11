#!/bin/bash

# First install KaMIS (independent set solver).
cd external/KaMIS-2.0/
bash compile_withcmake.sh
cd ../../

# Second build the program for monotonic matrices.
mkdir -p build
cd build/
cmake ..
make

# Done.
echo "Installation finished successfully."
