cmake_minimum_required(VERSION 3.10)
project(SLISC0)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

set(CMAKE_CXX_FLAGS "-std=c++11")

# === CBLAS ==
add_definitions(-D SLS_USE_CBLAS)
list(APPEND LIBS cblas blas)

# === LAPACKE ===
add_definitions(-D SLS_USE_LAPACKE)
list(APPEND LIBS lapacke lapack)

# === Boost ===
add_definitions(-D SLS_USE_BOOST)
list(APPEND LIBS boost_system boost_filesystem)

# === GSL ===
add_definitions(-D SLS_USE_GSL)
list(APPEND LIBS gsl)

# === Eigen ===
add_definitions(-D SLS_USE_EIGEN)

# === quad math ===
add_definitions(-D SLS_USE_QUAD_MATH)
add_compile_options(-fext-numeric-literals)
list(APPEND LIBS quadmath)

# === MPLAPACK ===
add_definitions(-D SLS_USE_MPLAPACK)
list(APPEND LIBS mplapack__Float128 mpblas__Float128)

# === Arpack ===
add_definitions(-D SLS_USE_ARPACK)
list(APPEND LIBS arpack gfortran)

# === Arb ===
add_definitions(-D SLS_USE_ARB)
list(APPEND LIBS flint mpfr gmp flint-arb) # replace flint-arb with arb if compiled yourself

# === Address Sanitizer ===
add_definitions(-D SLS_USE_ASAN)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -static-libasan")

# === Matfile ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
#add_definitions(-D SLS_USE_MATFILE)
#include_directories(../MatFile_linux/include)
#link_directories(../MatFile_linux/lib)
#list(APPEND LIBS mat mx)
#set(CMAKE_INSTALL_RPATH ../MatFile_linux/lib)

# === SQLite ===
add_definitions(-D SLS_USE_SQLITE)
list(APPEND LIBS sqlite3)

# === Debug ===
add_compile_options(-g -ftrapv)
# === Release ===
# add_definitions(-D NDEBUG)
# add_compile_options(-O3)

# add_definitions(-D SLS_USE_INT_AS_LONG)
add_compile_options(-Wall -Wno-reorder -Wno-cpp -Wno-misleading-indentation -fopenmp -fmax-errors=2)

file(GLOB SOURCES "test/*.cpp" "main.cpp")

add_executable(main.x ${SOURCES})

# precompile header (total compilation time remains the same, but single recompilation might be slower. Can help to check `#pragma once` and `inline` before functions if they are missing)
# file(GLOB SLISC_HEADERS "SLISC/*.h")
# file(GLOB STL_HEADERS "/usr/include/c++/9/*")
# list(REMOVE_ITEM STL_HEADERS /usr/include/c++/9/backward /usr/include/c++/9/bits /usr/include/c++/9/debug /usr/include/c++/9/decimal /usr/include/c++/9/experimental /usr/include/c++/9/ext /usr/include/c++/9/parallel /usr/include/c++/9/profile /usr/include/c++/9/pstl /usr/include/c++/9/tr1 /usr/include/c++/9/tr2)
# target_precompile_headers(main.x PRIVATE ${STL_HEADERS} ${SLISC_HEADERS})

# link
target_link_libraries(main.x ${LIBS})
