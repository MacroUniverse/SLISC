cmake_minimum_required(VERSION 3.10)
project(SLISC0)

set(CMAKE_CXX_COMPILER "/usr/bin/g++")

SET(CMAKE_CXX_FLAGS "-std=c++11")

# include_directories(SLISC)

# CBLAS
add_definitions(-D SLS_USE_CBLAS)
list(APPEND LIBS blas)
# LAPACKE
add_definitions(-D SLS_USE_LAPACKE)
list(APPEND LIBS lapacke)
# Boost
add_definitions(-D SLS_USE_BOOST)
include_directories(../boost-headers)
list(APPEND LIBS boost_system boost_filesystem)
# GSL
add_definitions(-D SLS_USE_GSL)
list(APPEND LIBS gsl)
# Eigen
add_definitions(-D SLS_USE_EIGEN)
include_directories(../EigenTest/Eigen)
# quad math
add_definitions(-D SLS_USE_QUAD_MATH)
add_compile_options(-fext-numeric-literals)
list(APPEND LIBS quadmath)
# Arpack
# add_definitions(-D SLS_USE_ARPACK)
# include_directories(../Arpack_test/include)
# list(APPEND LIBS arpack gfortran)
# Arb
add_definitions(-D SLS_USE_ARB)
include_directories(/usr/include/flint/)
list(APPEND LIBS flint mpfr gmp arb)
# Address Sanitizer
# add_definitions(-D SLS_USE_ASAN)
# add_compile_options(-fsanitize=address -static-libasan)
# Matfile
add_definitions(-D SLS_USE_MATFILE)
include_directories(../MatFile_linux/include)
LINK_DIRECTORIES(../MatFile_linux/bin)
list(APPEND LIBS mat mx)
set(CMAKE_INSTALL_RPATH ../MatFile_linux/bin)
# SQLite
add_definitions(-D SLS_USE_SQLITE)
list(APPEND LIBS sqlite3)

add_compile_options(-Wall -Wno-reorder -Wno-misleading-indentation -fopenmp -g -fmax-errors=2)

file(GLOB SOURCES "test/*.cpp" "main.cpp")

add_executable(main.x ${SOURCES})
target_link_libraries(main.x ${LIBS})
