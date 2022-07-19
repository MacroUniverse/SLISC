cmake_minimum_required(VERSION 3.10)
project(SLISC0)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

SET(CMAKE_CXX_FLAGS "-std=c++11")

# include_directories(SLISC)

add_definitions(-D SLS_USE_QUAD_MATH)
add_compile_options(-fext-numeric-literals)


add_compile_options(-Wall -Wno-reorder -Wno-misleading-indentation -fopenmp -g -fmax-errors=2)

file(GLOB SOURCES "test/*.cpp" "main.cpp")

add_executable(main.x ${SOURCES})
target_link_libraries(main.x quadmath)
