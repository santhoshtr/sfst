cmake_minimum_required(VERSION 3.1)

find_package(FLEX 2.6.4)
find_package(BISON)

set(CMAKE_CXX_FLAGS "-O3 -Wall -std=c++11 -ansi")

include_directories(${CMAKE_CURRENT_BINARY_DIR})
include_directories(.)

if(BISON_FOUND)
    BISON_TARGET(sfst fst-compiler.yy ${CMAKE_CURRENT_BINARY_DIR}/fst-compiler.cpp DEFINES_FILE ${CMAKE_CURRENT_BINARY_DIR}/fst-compiler.h)
else()
    message(STATUS "Bison not found, so executables won't be generated.")
endif()

if(FLEX_FOUND)
    FLEX_TARGET(sfst default-scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/default-scanner.cpp COMPILE_FLAGS --nounput)
    FLEX_TARGET(sfst utf8-scanner.ll ${CMAKE_CURRENT_BINARY_DIR}/utf8-scanner.cpp COMPILE_FLAGS --nounput)
else()
    message(STATUS "Flex not found, so executables won't be generated.")
endif()

# Include dir
include_directories(/usr/local/include)

# Source files
set (LIB_SOURCES
    basic.cpp utf8.cpp alphabet.cpp fst.cpp operators.cpp determinise.cpp hopcroft.cpp
)

set(HEADERS
    alphabet.h basic.h fst.h interface.h mem.h utf8.h ${CMAKE_CURRENT_BINARY_DIR}/fst-compiler.h
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
    add_executable(fst-compiler compact.cpp make-compact.cpp interface.cpp
    default-scanner.cpp fst-compiler.cpp)
    target_link_libraries(fst-compiler libsfst)
    target_link_libraries(fst-compiler readline)

    add_executable(fst-compiler-utf8 compact.cpp make-compact.cpp interface.cpp
    utf8-scanner.cpp fst-compiler.cpp)
    target_link_libraries(fst-compiler-utf8 libsfst)
    target_link_libraries(fst-compiler-utf8 readline)

    add_executable(fst-mor fst-mor.cpp)
    target_link_libraries(fst-mor libsfst)

    add_executable(fst-text2bin fst-text2bin.cpp)
    target_link_libraries(fst-text2bin libsfst)

    add_executable(fst-infl2 fst-infl2.cpp compact.cpp robust.cpp)
    target_link_libraries(fst-infl2 libsfst)

    add_executable(fst-infl2-daemon fst-infl2-daemon.cpp compact.cpp robust.cpp)
    target_link_libraries(fst-infl2-daemon libsfst)

    add_executable(fst-infl3 fst-infl3.cpp lowmem.cpp)
    target_link_libraries(fst-infl3 libsfst)

    add_executable(fst-infl fst-infl.cpp)
    target_link_libraries(fst-infl libsfst)

    add_executable(fst-train fst-train.cpp compact.cpp)
    target_link_libraries(fst-train libsfst)

    add_executable(fst-match fst-match.cpp compact.cpp )
    target_link_libraries(fst-match libsfst)

    add_executable(fst-generate fst-generate.cpp generate.cpp)
    target_link_libraries(fst-generate libsfst)

    add_executable(fst-compact fst-compact.cpp make-compact.cpp compact.cpp)
    target_link_libraries(fst-compact libsfst)

    add_executable(fst-parse fst-parse.cpp)
    target_link_libraries(fst-parse libsfst)

    add_executable(fst-print fst-print.cpp)
    target_link_libraries(fst-print libsfst)

    add_executable(fst-lattice fst-lattice.cpp)
    target_link_libraries(fst-lattice libsfst)

    add_executable(fst-lowmem fst-lowmem.cpp)
    target_link_libraries(fst-lowmem libsfst)


    # Install
    install(TARGETS fst-compact fst-generate fst-infl2 fst-lattice fst-match  fst-parse fst-text2bin fst-compiler fst-compiler-utf8 fst-infl fst-infl3 fst-lowmem fst-mor fst-print fst-train
        RUNTIME DESTINATION bin)
endif()

install(TARGETS libsfst
    RUNTIME DESTINATION lib)

# Install the headers
install(FILES ${HEADERS} DESTINATION include)

file(GLOB_RECURSE SOURCE_FILES *.cpp)

find_program(CLANG_TIDY NAMES clang-tidy)
if (CLANG_TIDY)
    add_custom_target(
        clang-tidy
        COMMAND ${CLANG_TIDY}
        ${SOURCE_FILES}
        --
        -std=c++11
    )
endif ()
