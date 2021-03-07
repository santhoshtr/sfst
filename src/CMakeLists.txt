cmake_minimum_required(VERSION 3.1)

find_package(FLEX)
find_package(BISON)

set(CMAKE_CXX_FLAGS "-O3 -Wall -Wcast-qual -Wconversion -std=c++11 -Wno-deprecated -ansi")

add_definitions(-DSGI__gnu_cxx)

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

if(BISON_FOUND)
    BISON_TARGET(sfst fst-compiler.yy ${CMAKE_CURRENT_BINARY_DIR}/fst-compiler.C DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/fst-compiler.h)
else()
    message(STATUS "Bison not found, so executables won't be generated.")
endif()

if(FLEX_FOUND)
    FLEX_TARGET(sfst default-scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/default-scanner.C)
    FLEX_TARGET(sfst utf8-scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/utf8-scanner.C)
else()
    message(STATUS "Flex not found, so executables won't be generated.")
endif()

# Include dir
include_directories(/usr/local/include)

# Source files
set (LIB_SOURCES
    basic.C utf8.C alphabet.C fst.C operators.C determinise.C hopcroft.C
)

set(HEADERS
    alphabet.h basic.h fst.h interface.h mem.h sgi.h utf8.h fst-compiler.h
)

# Add library
add_library(libsfst SHARED ${LIB_SOURCES})
set_target_properties(libsfst PROPERTIES POSITION_INDEPENDENT_CODE ON)
# Have the output name libsfst.so
set_target_properties(libsfst PROPERTIES OUTPUT_NAME "sfst")

# Have a static library
add_library(libsfststatic STATIC ${LIB_SOURCES})
set_target_properties(libsfststatic PROPERTIES POSITION_INDEPENDENT_CODE ON)
set_target_properties(libsfststatic PROPERTIES OUTPUT_NAME "sfst.static")

if(BISON_FOUND AND FLEX_FOUND)
    add_executable(fst-compiler-utf8 compact.C make-compact.C interface.C
    utf8-scanner.C fst-compiler.C)
    target_link_libraries(fst-compiler-utf8 libsfst)
    target_link_libraries(fst-compiler-utf8 readline)

    add_executable(fst-mor fst-mor.C)
    target_link_libraries(fst-mor libsfst)

    add_executable(fst-text2bin fst-text2bin.C)
    target_link_libraries(fst-text2bin libsfst)

    add_executable(fst-infl2 fst-infl2.C compact.C robust.C)
    target_link_libraries(fst-infl2 libsfst)

    add_executable(fst-infl3 fst-infl3.C lowmem.C)
    target_link_libraries(fst-infl3 libsfst)

    add_executable(fst-infl fst-infl.C)
    target_link_libraries(fst-infl libsfst)

    add_executable(fst-train fst-train.C compact.C)
    target_link_libraries(fst-train libsfst)

    add_executable(fst-match fst-match.C compact.C )
    target_link_libraries(fst-match libsfst)

    add_executable(fst-generate fst-generate.C generate.C)
    target_link_libraries(fst-generate libsfst)

    add_executable(fst-compact fst-compact.C make-compact.C compact.C)
    target_link_libraries(fst-compact libsfst)

    add_executable(fst-parse fst-parse.C)
    target_link_libraries(fst-parse libsfst)

    add_executable(fst-print fst-print.C)
    target_link_libraries(fst-print libsfst)

    add_executable(fst-lattice fst-lattice.C)
    target_link_libraries(fst-lattice libsfst)

    add_executable(fst-lowmem fst-lowmem.C)
    target_link_libraries(fst-lowmem libsfst)
endif()

# Install
install(TARGETS fst-compact fst-generate fst-infl2 fst-lattice fst-match  fst-parse fst-text2bin fst-compiler-utf8 fst-infl fst-infl3 fst-lowmem fst-mor fst-print fst-train libsfst
    RUNTIME DESTINATION bin
    RUNTIME DESTINATION lib)

# Install the headers
install(FILES ${HEADERS} DESTINATION include)


