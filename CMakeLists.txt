cmake_minimum_required(VERSION 3.0.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wcast-qual -Wconversion -std=c++11 -Wno-deprecated -ansi")

set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_definitions(-DSGI__gnu_cxx)

project(sfst VERSION 0.1.0)

include_directories("${CMAKE_SOURCE_DIR}/src")
include_directories("${CMAKE_SOURCE_DIR}/python")

file (GLOB SOURCE_FILES "src/basic.C src/utf8.C src/alphabet.C src/fst.C src/operators.C src/determinise.C src/hopcroft.C")
file (GLOB HEADER_FILES "src/*.h")
file (GLOB PYTHON_FILES "python/*.cpp" "python/*.h")

include(CTest)
include(pybind11.cmake)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

set (SFSTSOURCES src/basic.C src/utf8.C src/alphabet.C src/fst.C src/operators.C src/determinise.C src/hopcroft.C)
add_library(sfst STATIC ${SFSTSOURCES})
set_target_properties(sfst PROPERTIES POSITION_INDEPENDENT_CODE ON)

pybind11_add_module(pysfst
	${SOURCE_FILES}
	${HEADER_FILES}
	${PYTHON_FILES}
)

target_link_libraries(pysfst PRIVATE sfst)
