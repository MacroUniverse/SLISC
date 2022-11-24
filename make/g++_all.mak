# use g++ with libraries
# requires g++8.3 or higher
# any change in *.h.in file will cause all *.cpp files to compile
# to debug only one file, e.g. test_a.cpp, use `make test_a.o link`

#======== options =========
# compiler [g++|clang++|icpc|icpx]
opt_compiler = g++
# define Long (array index type) as 32bit integer
opt_long32 = true
# debug mode
opt_debug = true
# address sanitizer (only for g++ for now)
opt_asan = true
# c++ standard [c++11|gnu++11]
opt_std = c++11
# static link (only for MKL for now)
opt_static = false
# minimum build (all below options set to false)
opt_min = false
# use quad precision float
opt_quadmath = false
# lapack package (reference, openblas, mkl, none)
opt_lapack = reference
# use MPLAPACK lib
opt_mplapack = $(opt_quadmath)
# use Boost lib
opt_boost = true
# use GSL lib
opt_gsl = true
# use Eigen lib
opt_eigen = true
# use Arblib lib
opt_arb = true
# use Arpack++2 lib
opt_arpack = true
# use sqlite
opt_sqlite = true
# read and write Matlab .mat file
opt_matfile = false
#==========================

# === minimum build ===
ifeq ($(opt_min), true)
    opt_quadmath = false
    opt_mplapack = false
    opt_lapack = none
    opt_boost = false
    opt_gsl = false
    opt_eigen = false
    opt_arb = false
    opt_arpack = false
    opt_sqlite = false
    opt_matfile = false
endif

ifeq ($(opt_compiler), icpc)
    icpc_or_icpx = true
endif
ifeq ($(opt_compiler), icpx)
    icpc_or_icpx = true
endif

# === Debug / Release ===
ifeq ($(opt_debug), true)
    # Address Sanitizer
    ifeq ($(opt_asan), true)
    ifeq ($(opt_compiler), g++)
        asan_flag = -fsanitize=address -static-libasan -D SLS_USE_ASAN
    endif
    endif
    debug_flag = -g
    ifeq ($(opt_compiler), g++)
        debug_flag = -g -ftrapv $(asan_flag)
    endif
else
    release_flag = -O3 -D NDEBUG
endif

# === 64bit index ===
ifeq ($(opt_long32), true)
    long_flag = -D SLS_USE_INT_AS_LONG
endif

ifeq ($(opt_lapack), reference)
# === CBLAS (reference) ===
    cblas_flag = -D SLS_USE_CBLAS
    ifeq ($(opt_long32), false)
        cblas_lib = -l cblas64
    else
        cblas_lib = -l cblas
    endif
# === LAPACKE (reference) ===
    lapacke_flag = -D SLS_USE_LAPACKE
    ifeq ($(opt_long32), false)
        lapacke_lib = -l lapacke64
    else
        lapacke_lib = -l lapacke
    endif
endif

ifeq ($(opt_lapack), openblas)
# === CBLAS (openblas) ===
    cblas_flag = -D SLS_USE_CBLAS -I /opt/OpenBLAS/include
    cblas_lib = -l openblas
# === LAPACKE (openblas) ===
    lapacke_flag = -D SLS_USE_LAPACKE
endif

# === MKL ===
# ref: MKL link advisor https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor
ifeq ($(opt_lapack), mkl)
    ifeq ($(opt_compiler), g++)
        mkl_flag = -D SLS_USE_MKL -m64 -I${MKLROOT}/include
        ifeq ($(opt_static), true) # static link
            mkl_stat_link = -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -l pthread -l m -l dl
        else # dynamic link
            mkl_dyn_link = -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -l mkl_intel_lp64 -l mkl_sequential -l mkl_core -l pthread -l m -l dl
        endif
    endif
    ifeq ($(icpc_or_icpx), true)
        mkl_flag = -D SLS_USE_MKL -I${MKLROOT}/include
        ifeq ($(opt_static), true) # static link
            mkl_stat_link = -static -Wl,--start-group ${MKLROOT}/lib/intel64/libmkl_intel_lp64.a ${MKLROOT}/lib/intel64/libmkl_sequential.a ${MKLROOT}/lib/intel64/libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
        else # dynamic link
            mkl_dyn_link = -L${MKLROOT}/lib/intel64 -lmkl_rt -lpthread -lm -ldl
        endif
    endif
endif

# === Boost ===
ifeq ($(opt_boost), true)
    boost_flag = -D SLS_USE_BOOST
    boost_lib = -l boost_system -l boost_filesystem
endif

# === GSL ===
ifeq ($(opt_gsl), true)
    gsl_flag = -D SLS_USE_GSL
    gsl_lib = -l gsl
endif

# === Eigen ===
ifeq ($(opt_eigen), true)
    eigen_flag = -D SLS_USE_EIGEN
endif

# === Quad Math ===
ifeq ($(opt_quadmath), true)
    quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
    quad_math_lib = -l quadmath
endif

# === Arb ===
ifeq ($(opt_arb), true)
    arb_flag = -D SLS_USE_ARB
    arb_lib = -l flint -l mpfr -l gmp -l flint-arb # use -larb if compiled from source, or create soft link named flint-arb
endif

# === MPLAPACK ===
ifeq ($(opt_mplapack), true)
    mplapack_flag = -D SLS_USE_MPLAPACK
    mplapack_lib = -l mplapack__Float128 -l mpblas__Float128
endif

# === Arpack ===
ifeq ($(opt_arpack), true)
ifeq ($(opt_lapack), reference) # only works for reference lapack for now
    arpack_flag = -D SLS_USE_ARPACK
    arpack_lib = -l arpack -l gfortran -l blas -l lapack
endif
endif

# === SQLite ===
ifeq ($(opt_sqlite), true)
    sqlite_flag = -D SLS_USE_SQLITE
    sqlite_lib = -l sqlite3
endif

# === Matlab .mat file ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
ifeq ($(opt_matfile), true)
    matfile_bin_path = ../MatFile_linux/lib
    matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
    matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L $(matfile_bin_path) -l mat -l mx
endif

# === compiler flags ===
ifeq ($(opt_compiler), g++)
    compiler_flag = -std=$(opt_std) -Wall -Wno-cpp -Wno-reorder -Wno-misleading-indentation -fmax-errors=20 -fopenmp
endif
ifeq ($(opt_compiler), clang++)
    compiler_flag = -std=$(opt_std) -Wall -Wno-reorder -Wno-misleading-indentation
endif
ifeq ($(opt_compiler), icpc)
    compiler_flag = -std=$(opt_std) -Wall -fp-model precise -fp-model except -qopenmp -Qoption,cpp,--extended_float_type
endif
ifeq ($(opt_compiler), icpx)
    compiler_flag = -std=$(opt_std) -Wall -fp-model precise -qopenmp -Qoption,cpp,--extended_float_types -Wno-reorder-ctor -Wno-overloaded-virtual
endif

# ---------------------------------------------------------

# all flags
flags = $(compiler_flag) $(debug_flag) $(release_flag) $(mkl_flag) $(cblas_flag) $(lapacke_flag)  $(arpack_flag)  $(boost_flag) $(gsl_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(matfile_flag) $(sqlite_flag) $(long_flag) $(mplapack_flag)
# -pedantic # show more warnings

# all libs
libs = $(boost_lib) $(arb_lib) $(arpack_lib)  $(matfile_lib) $(sqlite_lib) $(mkl_stat_link) $(mkl_dyn_link) $(lapacke_lib) $(cblas_lib) $(quad_math_lib) $(gsl_lib) $(mplapack_lib)

# === File Lists ===
test_cpp = $(shell cd test && echo *.cpp) # test/*.cpp (no path)
test_o = $(test_cpp:.cpp=.o) # test/*.cpp object files (no path)
header_in = $(shell cd SLISC && echo *.h.in) # SLISC/*.h.in (no path)
gen_headers = $(header_in:.h.in=.h) # generated headers in SLISC/ (no path)
path_gen_headers = $(addprefix SLISC/,$(gen_headers)) # (with path)
cur_headers = $(shell cd SLISC && echo *.h) # current headers in SLISC/, including hand written ones (no path)
headers = $(gen_headers) $(cur_headers) # all headers (no path)
path_headers = $(addprefix SLISC/,$(headers)) # (with path)

goal: main.x

h: # remake all headers
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/','../test/'}, [], $(opt_quadmath), $(opt_long32))"

main.x: main.o $(test_o) # link
	@printf "\n\n   --- link ---\n\n"
	$(opt_compiler) $(flags) -o main.x main.o test_*.o $(libs)

link: # force link
	$(opt_compiler) $(flags) -o main.x main.o test_*.o $(libs)

clean:
	rm -f *.o *.x

clean_h:
	rm -f $(path_gen_headers)

main.o: main.cpp test/test_all.h
	$(opt_compiler) $(flags) -c main.cpp

%.o: test/%.cpp $(path_headers)
	$(opt_compiler) $(flags) -c $<

%.h: %.h.in # code gen
	octave --no-window-system --eval "cd preprocessor; auto_gen({'../SLISC/'}, '$$(basename $<)', $(opt_quadmath), $(opt_long32))"
