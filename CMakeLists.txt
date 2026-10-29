cmake_minimum_required(VERSION 3.24)

# Use Clang 22 unless a compiler was picked on the command line.
# This has to come before project().
if(NOT DEFINED CMAKE_CXX_COMPILER)
    set(CMAKE_CXX_COMPILER clang++-22)
endif()

project(CodeForces LANGUAGES CXX)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)   # for clangd / IntelliSense
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# libc++ provides <print> (the system libstdc++ 13 does not).
add_compile_options(-stdlib=libc++ -Wall -Wextra)
add_link_options(-stdlib=libc++)

# Debug: catch out-of-bounds, overflow, etc. Release: like Codeforces (-O2).
set(SANITIZERS -fsanitize=address,undefined -fno-omit-frame-pointer)
add_compile_options("$<$<CONFIG:Debug>:${SANITIZERS}>")
add_link_options("$<$<CONFIG:Debug>:${SANITIZERS}>")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")

# One executable per .cpp file, named after the file
# (spaces and other odd characters become "_").
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS "${CMAKE_SOURCE_DIR}/*.cpp")
list(FILTER SOURCES EXCLUDE REGEX "/(build|\\.git)/")

foreach(src IN LISTS SOURCES)
    get_filename_component(name "${src}" NAME_WE)
    string(REGEX REPLACE "[^A-Za-z0-9_.+-]" "_" name "${name}")

    # Two files with the same name: add a number to keep targets unique.
    set(target "${name}")
    set(i 2)
    while(TARGET "${target}")
        set(target "${name}_${i}")
        math(EXPR i "${i} + 1")
    endwhile()

    add_executable("${target}" "${src}")
endforeach()
