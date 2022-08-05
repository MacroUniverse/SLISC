cmake_minimum_required(VERSION 3.0)
project(test)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")
set(CMAKE_CXX_FLAGS "-std=c++11")

# quad math
# add_definitions(-D SLS_USE_QUAD_MATH)
# add_compile_options(-fext-numeric-literals)
# list(APPEND LIBS quadmath)
# Address Sanitizer
add_definitions(-D SLS_USE_ASAN)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -static-libasan")
add_compile_options(-Wall -Wno-reorder -Wno-misleading-indentation -g -fmax-errors=4)
add_executable(main.x main.cpp)
target_link_libraries(main.x ${LIBS})
