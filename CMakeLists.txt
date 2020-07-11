# CMake version.
cmake_minimum_required (VERSION 2.8)

project("Monotone Matrices")

# Compiler flags.
set(CMAKE_CXX_FLAGS "-std=c++2a -Wall -Wextra -O2")

# Compile the executables.
add_executable(graph_gen src/graph_gen.cpp)
add_executable(is2text src/is2text.cpp)
add_executable(text2svg src/text2svg.cpp)
