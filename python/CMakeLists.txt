if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wcast-qual -Wconversion -std=c++11 -Wno-deprecated -ansi")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_definitions(-DSGI__gnu_cxx)

include(CTest)
include(pybind11.cmake)
enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

pybind11_add_module(sfst
	sfst.cpp
)
target_compile_definitions(sfst PRIVATE VERSION_INFO=${VERSION_INFO})

target_link_libraries(sfst PRIVATE libsfststatic)
