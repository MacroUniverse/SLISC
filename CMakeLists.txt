cmake_minimum_required(VERSION 3.10)
project(SLISC0)

# == options ===
set(opt_compiler "g++" CACHE STRING "")
set(opt_long32 TRUE CACHE BOOL "use 32bit integer or 64bit integer for indexing (Long type)")
set(opt_debug TRUE CACHE BOOL "")
set(opt_asan TRUE CACHE BOOL "")
set(opt_std "c++11" CACHE STRING "")
set(opt_static FALSE CACHE BOOL "")
set(opt_min FALSE CACHE BOOL "")
set(opt_quadmath FALSE CACHE BOOL "enable quadmath")
set(opt_lapack "reference" CACHE STRING "")
set(opt_mplapack ${opt_quadmath} CACHE BOOL "")
set(opt_boost TRUE CACHE BOOL "enable boost")
set(opt_gsl TRUE CACHE BOOL "")
set(opt_eigen TRUE CACHE BOOL "")
set(opt_arb TRUE CACHE BOOL "")
set(opt_arpack TRUE CACHE BOOL "enable arpack")
set(opt_sqlite TRUE CACHE BOOL "")
set(opt_matfile FALSE CACHE BOOL "")
set(opt_no__Float128 FALSE CACHE BOOL "")
# ==============

set(CMAKE_CXX_COMPILER "/usr/bin/${opt_compiler}")

set(CMAKE_CXX_FLAGS "-std=${opt_std}")

# === 64bit index ===
if (opt_long32)
	add_definitions(-D SLS_USE_INT_AS_LONG)
endif()

# === GSL ===
if(opt_gsl)
	add_definitions(-D SLS_USE_GSL)
	list(APPEND LIBS gsl)
endif()

if(opt_lapack STREQUAL reference)

# === Arpack ===
if(opt_arpack)
	add_definitions(-D SLS_USE_ARPACK)
	list(APPEND LIBS arpack gfortran)
endif()

# === MPLAPACK ===
if(opt_mplapack)
	add_definitions(-D SLS_USE_MPLAPACK)
	list(APPEND LIBS mplapack__Float128 mpblas__Float128)
endif()

# === LAPACKE ===
add_definitions(-D SLS_USE_LAPACKE)
	if($(opt_long32) EQUAL FALSE)
		list(APPEND LIBS lapacke64 lapack64)
    else()
		list(APPEND LIBS lapacke lapack)
    endif()
else()
	message(FATAL_ERROR "not implemented!")
endif()

# === CBLAS ===
add_definitions(-D SLS_USE_CBLAS)
if($(opt_long32) EQUAL FALSE)
	list(APPEND LIBS cblas64 blas64 gfortran quadmath)
else()
	list(APPEND LIBS cblas blas gfortran quadmath)
endif()

# === Boost ===
if(opt_boost)
	add_definitions(-D SLS_USE_BOOST)
	list(APPEND LIBS boost_system boost_filesystem)
endif()

# === Eigen ===
if(opt_eigen)
	add_definitions(-D SLS_USE_EIGEN)
endif()

# === quad math ===
if(opt_quadmath)
	add_definitions(-D SLS_USE_QUAD_MATH)
	add_compile_options(-fext-numeric-literals)
	list(APPEND LIBS quadmath)
endif()

# === Arb ===
if(opt_arb)
	add_definitions(-D SLS_USE_ARB)
	list(APPEND LIBS flint-arb flint mpfr gmp) # replace flint-arb with arb if compiled yourself
endif()

# === Address Sanitizer ===
if(opt_asan)
	add_definitions(-D SLS_USE_ASAN)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
	set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -static-libasan")
endif()

# === Matfile ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
if(opt_matfile)
	add_definitions(-D SLS_USE_MATFILE)
	include_directories(../MatFile_linux/include)
	link_directories(../MatFile_linux/lib)
	list(APPEND LIBS mat mx)
	set(CMAKE_INSTALL_RPATH ../MatFile_linux/lib)
endif()

# === SQLite ===
if(opt_sqlite)
	add_definitions(-D SLS_USE_SQLITE)
	list(APPEND LIBS sqlite3)
endif()

# === Debug/Release ===
if(opt_debug)
	add_compile_options(-g -ftrapv)
else()
	add_definitions(-D NDEBUG)
	add_compile_options(-O3)
endif()

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
