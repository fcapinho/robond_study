cmake_minimum_required(VERSION 3.5)

# set the project name
project(A_STAR VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# add the executable
add_executable(a_star main.cpp)

# copy map file
configure_file(map.txt map.txt COPYONLY)