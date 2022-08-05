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
file(GLOB SLISC_HEADERS "../SLISC/*.h")
file(GLOB STL_HEADERS "/usr/include/c++/9/*")
list(REMOVE_ITEM STL_HEADERS /usr/include/c++/9/backward /usr/include/c++/9/bits /usr/include/c++/9/debug /usr/include/c++/9/decimal /usr/include/c++/9/experimental /usr/include/c++/9/ext /usr/include/c++/9/parallel /usr/include/c++/9/profile /usr/include/c++/9/pstl /usr/include/c++/9/tr1 /usr/include/c++/9/tr2)
target_precompile_headers(main.x PRIVATE ${STL_HEADERS} ${SLISC_HEADERS})
target_link_libraries(main.x ${LIBS})

# message(STATUS "${STL_HEADERS}")