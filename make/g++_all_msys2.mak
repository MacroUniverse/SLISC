# compile in msys2/mingw64
# 使用北太天元提供的 mingw64.exe
# 把 baltam-plugin-arb/windows/bin-arb4win 仓库中的所有 dll 拷贝到 mingw64 的 /usr/local/bin 新建目录下（默认的 dll 搜索路径， rpath 无效）
# 再修改 arb_path 以找到 baltam-plugin-arb/windows/include 中正确的头文件

compiler = g++

# CBLAS
# cblas_flag = -D SLS_USE_CBLAS
# cblas_lib = -lblas
# LAPACKE
# lapacke_flag = -D SLS_USE_LAPACKE
# lapacke_lib = -llapacke
# Boost
# boost_flag = -D SLS_USE_BOOST -I ../boost-headers
# boost_lib = -lboost_system -lboost_filesystem
# GSL
# gsl_flag = -D SLS_USE_GSL
# gsl_lib = -lgsl
# Eigen
# eigen_flag = -D SLS_USE_EIGEN -I ../EigenTest/Eigen
# Quad Math
# quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
# quad_math_lib = -lquadmath
# Arpack
# arpack_flag = -D SLS_USE_ARPACK -I ../Arpack_test/include
# arpack_lib = -larpack -lgfortran
# 

arb_path = /c/baltamatica/bex/test/plugins/arb/windows
arb_flag = -D SLS_USE_ARB -I $(arb_path)/include/flint -I $(arb_path)/include/flint/flintxx -I $(arb_path)/include/ -L /usr/local/bin
arb_lib = -l arb-2 -l mpfr-6 -l flint -l gmp-23 # use -larb if compiled from source, or create soft link named flint-arb
# Address Sanitizer
# asan_flag = -fsanitize=address -static-libasan -D SLS_USE_ASAN
# Matfile
# (conflicts with boost_filesystem.so other than version 1.56.0)
# matfile_bin_path = ../MatFile_linux/lib
# matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
# matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L$(matfile_bin_path) -l mat -l mx
# SQLite
# sqlite_flag = -D SLS_USE_SQLITE
# sqlite_lib = -l sqlite3
# Debug / Release
debug_flag = -g -ftrapv
# release_flag = -O3 -D NDEBUG

# All
flags = -Wall -Wno-reorder -Wno-misleading-indentation -std=c++11 -fopenmp $(debug_flag) $(release_flag) -fmax-errors=20 $(arpack_flag) $(cblas_flag) $(lapacke_flag) $(boost_flag) $(gsl_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(asan_flag) $(matfile_flag) $(sqlite_flag) -D SLS_USE_INT_AS_LONG

libs = $(gsl_lib) $(lapacke_lib) $(boost_lib) $(cblas_lib) $(arb_lib) $(arpack_lib) $(quad_math_lib) $(matfile_lib) $(sqlite_lib)

# file lists
test_cpp = $(shell cd test && echo *.cpp) # test/*.cpp (no path)
test_o = $(test_cpp:.cpp=.o) # test/*.cpp object files (no path)
header_in = $(shell cd SLISC && echo *.h.in) # SLISC/*.h.in (no path)
gen_headers = $(header_in:.h.in=.h) # generated headers in SLISC/ (no path)
path_gen_headers = $(addprefix SLISC/,$(gen_headers)) # (with path)
cur_headers = $(shell cd SLISC && echo *.h) # current headers in SLISC/, including hand written ones (no path)
headers = $(gen_headers) $(cur_headers) # all headers (no path)
path_headers = $(addprefix SLISC/,$(headers)) # (with path)

goal: main.x

main.x: main.o $(test_o)
	make link

h: # remake all headers
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/','../test/'}, [], false, true)"

link: # link only
	$(compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x $(path_gen_headers)

main.o: main.cpp test/test_all.h
	$(compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(compiler) $(flags) -c $<

%.h: %.h.in
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/'}, '$$(basename $<)', false, true)"
