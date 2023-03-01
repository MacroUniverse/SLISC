cmake_minimum_required(VERSION 3.10)
project(SLISC0)

# == options ===
set(opt_compiler "g++" CACHE STRING "")
set(opt_octave OFF CACHE BOOL "use octave for code generation")
set(opt_long32 ON CACHE BOOL "use 32bit integer or 64bit integer for indexing (Long type)")
set(opt_debug ON CACHE BOOL "")
set(opt_asan ON CACHE BOOL "")
set(opt_std "c++11" CACHE STRING "")
set(opt_static OFF CACHE BOOL "")
set(opt_min OFF CACHE BOOL "")
set(opt_quadmath OFF CACHE BOOL "enable quadmath")
set(opt_lapack "reference" CACHE STRING "")
set(opt_mplapack ${opt_quadmath} CACHE BOOL "")
set(opt_boost ON CACHE BOOL "enable boost")
set(opt_gsl ON CACHE BOOL "")
set(opt_eigen ON CACHE BOOL "")
set(opt_arb ON CACHE BOOL "")
set(opt_arpack ON CACHE BOOL "enable arpack")
set(opt_sqlite ON CACHE BOOL "")
set(opt_matfile OFF CACHE BOOL "")
set(opt_no__Float128 OFF CACHE BOOL "")
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

# === Arpack ===
if(opt_arpack)
	if(NOT opt_long32)
		message(STATUS "arpack: 64")
		add_definitions(-D SLS_USE_ARPACK)
		list(APPEND LIBS arpack64)
	else()
		message(STATUS "arpack: 32")
		add_definitions(-D SLS_USE_ARPACK)
		list(APPEND LIBS arpack)
	endif()
endif()

# === MPLAPACK ===
if(opt_mplapack)
	message(STATUS "mplapack: on")
	add_definitions(-D SLS_USE_MPLAPACK)
	list(APPEND LIBS mplapack__Float128 mpblas__Float128)
endif()

if(opt_lapack STREQUAL "reference")
	# === LAPACKE ===
	add_definitions(-D SLS_USE_LAPACKE)
	if(NOT opt_long32)
		message(STATUS "lapacke: ref64")
		list(APPEND LIBS lapacke64 lapack64 gfortran)
	else()
		message(STATUS "lapacke: ref32")
		list(APPEND LIBS lapacke lapack gfortran)
	endif()

	# === CBLAS ===
	add_definitions(-D SLS_USE_CBLAS)
	if(NOT opt_long32)
		message(STATUS "cblas: ref64")
		list(APPEND LIBS cblas64 blas64 gfortran)
	else()
		message(STATUS "cblas: ref32")
		list(APPEND LIBS cblas blas gfortran)
	endif()
else()
	message(FATAL_ERROR "not implemented!")
endif()

# === Boost ===
if(opt_boost)
	message(STATUS "boost: on")
	add_definitions(-D SLS_USE_BOOST)
	list(APPEND LIBS boost_system boost_filesystem)
endif()

# === Eigen ===
if(opt_eigen)
	message(STATUS "eigen: on")
	add_definitions(-D SLS_USE_EIGEN)
endif()

# === quad math ===
if(opt_quadmath)
	message(STATUS "quadmath: on")
	add_definitions(-D SLS_USE_QUAD_MATH)
	add_compile_options(-fext-numeric-literals)
	list(APPEND LIBS quadmath)
endif()

# === Arb ===
if(opt_arb)
	message(STATUS "arb: on")
	add_definitions(-D SLS_USE_ARB)
	list(APPEND LIBS flint-arb flint mpfr gmp) # replace flint-arb with arb if compiled yourself
endif()

# === Address Sanitizer ===
if(opt_asan)
	message(STATUS "asan: on")
	add_definitions(-D SLS_USE_ASAN)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
	set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -static-libasan")
endif()

# === Matfile ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
if(opt_matfile)
	message(STATUS "matfile: on")
	add_definitions(-D SLS_USE_MATFILE)
	include_directories(../MatFile_linux/include)
	link_directories(../MatFile_linux/lib)
	list(APPEND LIBS mat mx)
	set(CMAKE_INSTALL_RPATH ../MatFile_linux/lib)
endif()

# === SQLite ===
if(opt_sqlite)
	message(STATUS "sqlite: on")
	add_definitions(-D SLS_USE_SQLITE)
	list(APPEND LIBS sqlite3)
endif()

# === Debug/Release ===
if(opt_debug)
	message(STATUS "build: debug")
	add_compile_options(-g -ftrapv)
else()
	message(STATUS "build: release")
	add_definitions(-D NDEBUG)
	add_compile_options(-O3)
endif()

# === build *.h from *.h.in ===
if(opt_octave)
	message(STATUS "generation of code!")
	message(STATUS "CMAKE_CURRENT_BINARY_DIR: ${CMAKE_CURRENT_BINARY_DIR}")
	file(GLOB H_INs "SLISC/*.h.in")
	set(octave_quadmath, "false")
	if(opt_quadmath)
		set(octave_quadmath, "true")
	endif()
	set(octave_long32, "false")
	if(opt_long32)
		set(octave_long32, "true")
	endif()
	find_program(octave_cmd "octave")
	message(STATUS "octave_cmd: ${octave_cmd}")
	foreach(H_IN ${H_INs})
		message(STATUS "H_IN: ${H_IN}")
		string(REPLACE ".h.in" ".h"  H_OUT "${H_IN}")
		message(STATUS "H_OUT: ${H_OUT}")
		add_custom_command(OUTPUT ${H_OUT}
		  COMMAND ${octave_cmd} "--no-window-system" "--eval" "\"cd preprocessor; auto_gen({'../SLISC/'}, '${H_OUT}', ${octave_quadmath}, ${octave_long32})\""
		  DEPENDS "${H_IN}"
		  COMMENT "generating file: ${H_OUT}")
	endforeach()
endif()

add_compile_options(-Wall -Wno-reorder -Wno-cpp -Wno-misleading-indentation -fopenmp -fmax-errors=2)

file(GLOB SOURCES "test/*.cpp" "main.cpp")

add_executable(main.x ${SOURCES})

# precompile header (total compilation time remains the same, but single recompilation might be slower. Can help to check `#pragma once` and `inline` before functions if they are missing)
# file(GLOB SLISC_HEADERS "SLISC/*.h")
# file(GLOB STL_HEADERS "/usr/include/c++/9/*")
# list(REMOVE_ITEM STL_HEADERS /usr/include/c++/9/backward /usr/include/c++/9/bits /usr/include/c++/9/debug /usr/include/c++/9/decimal /usr/include/c++/9/experimental /usr/include/c++/9/ext /usr/include/c++/9/parallel /usr/include/c++/9/profile /usr/include/c++/9/pstl /usr/include/c++/9/tr1 /usr/include/c++/9/tr2)
# target_precompile_headers(main.x PRIVATE ${STL_HEADERS} ${SLISC_HEADERS})
# target_include_directories(main.x PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/SLISC")

# link
target_link_libraries(main.x ${LIBS})
