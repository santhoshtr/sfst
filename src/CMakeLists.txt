cmake_minimum_required(VERSION 3.1)
project(sfst VERSION 0.1.0)

find_package(FLEX)
find_package(BISON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "-O3 -Wall -Wcast-qual -Wconversion -std=c++11 -Wno-deprecated -ansi")

add_definitions(-DSGI__gnu_cxx)

FLEX_TARGET(sfst default-scanner.ll default-scanner.C)
FLEX_TARGET(sfst utf8-scanner.ll utf8-scanner.ll.C)
BISON_TARGET(sfst fst-compiler.yy fst-compiler.C DEFINES_FILE fst-compiler.h)

# Include dir
include_directories(/usr/local/include)

# Src
AUX_SOURCE_DIRECTORY(src SRC_FILES)

# Source files
set (LIB_OBJS
    basic.C utf8.C alphabet.C fst.C operators.C determinise.C hopcroft.C
)

set (CLI_PROGRAMS
    fst-compare.C
    fst-infl2.C
    fst-match.C
    fst-train.C
    fst-compiler.C
    fst-infl2-daemon.C
    fst-mor.C
    fst-compiler.h
    fst-infl3.C
    fst-parse2.C
    fst-compiler.yy
    fst-infl.C
    fst-parse.C
    fst-generate.C
    fst-lattice.C
    fst-print.C
    fst-compact.C
    fst-lowmem.C
    fst-text2bin.C
)

set(HEADERS
    alphabet.h basic.h fst.h interface.h mem.h sgi.h utf8.h
)

set(SOURCE_FILES
    ${LIB_OBJS}
    ${CLI_PROGRAMS}
    ${HEADERS}
    lowmem.C
    make-compact.C
    robust.C
    make-compact.h
    interface.C
    default-scanner.C
    utf8-scanner.C
)

add_executable(fst-compiler-utf8 compact.C make-compact.C interface.C
utf8-scanner.C fst-compiler.C ${LIB_OBJS})
target_link_libraries(fst-compiler-utf8 readline)

add_executable(fst-mor fst-mor.C ${LIB_OBJS})
add_executable(fst-text2bin fst-text2bin.C ${LIB_OBJS})
add_executable(fst-infl2 fst-infl2.C compact.C robust.C ${LIB_OBJS})
add_executable(fst-infl3 fst-infl3.C lowmem.C ${LIB_OBJS})
add_executable(fst-infl fst-infl.C ${LIB_OBJS})
add_executable(fst-train fst-train.C compact.C ${LIB_OBJS})
add_executable(fst-match fst-match.C compact.C ${LIB_OBJS})
add_executable(fst-generate fst-generate.C generate.C ${LIB_OBJS})
add_executable(fst-compact fst-compact.C make-compact.C compact.C ${LIB_OBJS})
add_executable(fst-parse fst-parse.C ${LIB_OBJS})
add_executable(fst-lowmem fst-lowmem.C ${LIB_OBJS})

# Add library
add_library(sfst STATIC ${LIB_OBJS})
set_target_properties(sfst PROPERTIES POSITION_INDEPENDENT_CODE ON)

# Install
install(TARGETS sfst DESTINATION lib)

# Install the headers
install(FILES ${HEADERS} DESTINATION include)
