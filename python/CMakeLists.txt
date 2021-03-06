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

include(CTest)
include(pybind11.cmake)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

get_filename_component(SFSTDIR ../src ABSOLUTE)

set (SFSTLIBSOURCES
	${SFSTDIR}/basic.C
	${SFSTDIR}/utf8.C
	${SFSTDIR}/alphabet.C
	${SFSTDIR}/fst.C
	${SFSTDIR}/operators.C
	${SFSTDIR}/determinise.C
	${SFSTDIR}/hopcroft.C
)

add_library(libsfst STATIC ${SFSTLIBSOURCES})
set_target_properties(libsfst PROPERTIES POSITION_INDEPENDENT_CODE ON)

pybind11_add_module(sfst
	sfst.cpp
)

target_link_libraries(sfst PRIVATE libsfst)
