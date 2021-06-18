cmake_minimum_required(VERSION 3.13)
file(STRINGS "VERSION" SFST_VERSION)

project(sfst VERSION ${SFST_VERSION})

message(STATUS "Project name: ${PROJECT_NAME}")
message(STATUS "Project version: ${SFST_VERSION}")

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
set(CMAKE_CXX_EXTENSIONS OFF)

# Generate version.h to reflect our version number
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/src/version.h.in
               ${CMAKE_CURRENT_SOURCE_DIR}/src/version.h @ONLY)

# add library code
add_subdirectory(src)

# add python bindings
add_subdirectory(python)
