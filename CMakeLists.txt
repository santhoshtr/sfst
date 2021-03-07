cmake_minimum_required(VERSION 3.13)
file(READ "VERSION" VERSION)

project(sfst VERSION ${VERSION})

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# add library code
add_subdirectory(src)

# add python bindings
add_subdirectory(python)
