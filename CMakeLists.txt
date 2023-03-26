cmake_minimum_required(VERSION 3.10)
project(SLISC)

# == options ===
set(opt_compiler "g++" CACHE STRING "")
set(opt_octave ON CACHE BOOL "use Octave for code generation")
set(opt_long32 ON CACHE BOOL "use 32bit integer or 64bit integer for index type (Long)")
set(opt_debug ON CACHE BOOL "debug mode")
set(opt_asan ON CACHE BOOL "address sanitizer")
set(opt_std "c++11" CACHE STRING "c++ standard")
set(opt_static OFF CACHE BOOL "static compilation")
set(opt_min OFF CACHE BOOL "minimum build, disable all 3rd party libraries")
set(opt_quadmath OFF CACHE BOOL "enable quad precision support")
set(opt_lapack "reference" CACHE STRING "LAPACK: [reference|mkl|none]")
set(opt_mplapack ${opt_quadmath} CACHE BOOL "enable MPLAPACK")
set(opt_boost ON CACHE BOOL "enable Boost")
set(opt_gsl ON CACHE BOOL "enable GSL")
set(opt_eigen ON CACHE BOOL "enable Eigen")
set(opt_arb ON CACHE BOOL "enable Arb")
set(opt_arpack ON CACHE BOOL "enable Arpack")
set(opt_sqlite ON CACHE BOOL "enable Sqlite")
set(opt_matfile OFF CACHE BOOL "enable Matlab .mat file (deprecated)")
# ==============

message(STATUS "------------------------")

# === minimum build ===
if(opt_min)
    set(opt_quadmath OFF)
	set(opt_mplapack OFF)
	set(opt_lapack "none")
	set(opt_boost OFF)
	set(opt_gsl OFF)
	set(opt_eigen OFF)
	set(opt_arb OFF)
	set(opt_arpack OFF)
	set(opt_sqlite OFF)
	set(opt_matfile OFF)
	set(opt_asan OFF)
endif()

# === compiler ====
find_program(tmp ${opt_compiler})
set(CMAKE_CXX_COMPILER ${tmp})
message(STATUS "compiler: ${CMAKE_CXX_COMPILER}")

set(CMAKE_CXX_FLAGS "-std=${opt_std}")

# === 64bit index ===
if(opt_long32)
	message(STATUS "Long bits: 32")
else()
	message(STATUS "Long bits: 64")
endif()

# === GSL ===
if(opt_gsl)
	message(STATUS "gsl: on")
	add_definitions(-D SLS_USE_GSL)
	list(APPEND LIBS gsl)
else()
message(STATUS "gsl: off")
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
else()
	message(STATUS "arpack: off")
endif()

# === MPLAPACK ===
if(opt_mplapack)
	message(STATUS "mplapack: on")
	add_definitions(-D SLS_USE_MPLAPACK)
	list(APPEND LIBS mplapack__Float128 mpblas__Float128)
else()
	message(STATUS "mplapack: off")
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
elseif(opt_lapack STREQUAL "mkl")
	message(FATAL_ERROR "not implemented!")
else()
	message(STATUS "lapacke: off")
	message(STATUS "cblas: off")
endif()

# === Boost ===
if(opt_boost)
	message(STATUS "boost: on")
	add_definitions(-D SLS_USE_BOOST)
	list(APPEND LIBS boost_system boost_filesystem)
else()
	message(STATUS "boost: off")
endif()

# === Eigen ===
if(opt_eigen)
	message(STATUS "eigen: on")
	add_definitions(-D SLS_USE_EIGEN)
else()
	message(STATUS "eigen: off")
endif()

# === quad math ===
if(opt_quadmath)
	message(STATUS "quadmath: on")
	add_compile_options(-fext-numeric-literals)
	list(APPEND LIBS quadmath)
else()
	message(STATUS "quadmath: off")
endif()

# === Arb ===
if(opt_arb)
	message(STATUS "arb: on")
	add_definitions(-D SLS_USE_ARB)
	list(APPEND LIBS flint-arb flint mpfr gmp) # replace flint-arb with arb if compiled yourself
else()
	message(STATUS "arb: off")
endif()

# === Address Sanitizer ===
if(opt_asan)
	message(STATUS "asan: on")
	add_definitions(-D SLS_USE_ASAN)
	set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-omit-frame-pointer -fsanitize=address")
	set(CMAKE_LINKER_FLAGS "${CMAKE_LINKER_FLAGS} -fno-omit-frame-pointer -fsanitize=address -static-libasan")
else()
	message(STATUS "asan: off")
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
else()
	message(STATUS "matfile: off")
endif()

# === SQLite ===
if(opt_sqlite)
	message(STATUS "sqlite: on")
	add_definitions(-D SLS_USE_SQLITE)
	list(APPEND LIBS sqlite3)
else()
	message(STATUS "sqlite: off")
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

add_compile_options(-Wall -Wno-reorder -Wno-cpp -Wno-misleading-indentation -fopenmp -fmax-errors=2)

# get all .cpp and .h files
file(GLOB SOURCES "${PROJECT_SOURCE_DIR}/tests/*.cpp" "main.cpp")
file(GLOB HEADERS "${PROJECT_SOURCE_DIR}/SLISC/*.h" "${PROJECT_SOURCE_DIR}/SLISC/*/*.h")
file(GLOB HEADERS_IN "${PROJECT_SOURCE_DIR}/SLISC/*/*.h.in")
if (HEADERS_IN)
	string(REPLACE ".h.in" ".h"  HEADERS2 "${HEADERS_IN}")
	list(REMOVE_ITEM HEADERS ${HEADERS2})
endif()

# message(STATUS "HEADERS = ${HEADERS}")
# message(STATUS "HEADERS2 = ${HEADERS2}")

add_executable(main ${SOURCES} ${HEADERS} ${HEADERS2})
set_target_properties(main PROPERTIES OUTPUT_NAME main.x)

# === build *.h from *.h.in ===
if(opt_octave)
	file(GLOB H_INs "SLISC/*/*.h.in")
	# message(STATUS "H_Ins: ${H_INs}")
	set(octave_quadmath "false")
	if(opt_quadmath)
		set(octave_quadmath "true")
	endif()
	set(octave_long32 "false")
	if(opt_long32)
		set(octave_long32 "true")
	endif()
	foreach(H_IN ${H_INs})
		string(REPLACE ".h.in" ".h"  H_OUT "${H_IN}")
		get_filename_component(H_OUT0 "${H_OUT}" NAME)
		set(MY_CMD "octave --no-window-system --eval \"auto_gen({'../SLISC/','../tests/'}, '${H_OUT0}.in', ${octave_quadmath}, ${octave_long32})\"")
		string(REPLACE " " ";" MY_CMD ${MY_CMD})

		add_custom_command(OUTPUT "${H_OUT}"
		  COMMAND ${MY_CMD}
		  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/preprocessor
		  DEPENDS "${H_IN}"
		  COMMENT "generating file: ${H_OUT}")
	endforeach()
endif()

# precompile header (total compilation time remains the same, but single recompilation might be slower. Can help to check `#pragma once` and `inline` before functions if they are missing)

# file(GLOB SLISC_HEADERS "SLISC/*.h")
# file(GLOB STL_HEADERS "/usr/include/c++/9/*")
# list(REMOVE_ITEM STL_HEADERS /usr/include/c++/9/backward /usr/include/c++/9/bits /usr/include/c++/9/debug /usr/include/c++/9/decimal /usr/include/c++/9/experimental /usr/include/c++/9/ext /usr/include/c++/9/parallel /usr/include/c++/9/profile /usr/include/c++/9/pstl /usr/include/c++/9/tr1 /usr/include/c++/9/tr2)
# target_precompile_headers(main.x PRIVATE ${STL_HEADERS} ${SLISC_HEADERS})
# target_include_directories(main PUBLIC "${CMAKE_CURRENT_BINARY_DIR}/SLISC")

# link
target_link_libraries(main ${LIBS})

# clean_h
add_custom_target(clean_h
		  COMMAND rm -f ${HEADERS2} ${PROJECT_SOURCE_DIR}/tem_db.mat
		  COMMENT "removing generated headers and template database...")

# h
set(MY_CMD "octave --no-window-system --eval \"auto_gen({'../SLISC/','../tests/'}, [], ${octave_quadmath}, ${octave_long32})\"")
string(REPLACE " " ";" MY_CMD ${MY_CMD})
add_custom_target(h
		  COMMAND ${MY_CMD}
		  WORKING_DIRECTORY ${PROJECT_SOURCE_DIR}/preprocessor
		  DEPENDS ${HEADERS_IN}
		  COMMENT "generating all header files...")

message(STATUS "------------------------")
