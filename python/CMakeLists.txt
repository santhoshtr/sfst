if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE Release)
endif()

set(CMAKE_CXX_FLAGS "-O3 -Wall -std=c++17 -ansi")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

include(CTest)

enable_testing()

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

pybind11_add_module(sfst
	sfst.cpp
)
target_compile_definitions(sfst PRIVATE VERSION_INFO=${VERSION_INFO})

target_link_libraries(sfst PRIVATE libsfststatic)
