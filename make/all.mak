# use g++ with libraries
# requires g++8.3 or higher
# any change in *.h.in file will cause all *.cpp files to compile
# to debug only one file, e.g. test_a.cpp, use `make test_a.o link`

#======== options =========
# compiler [g++|clang++|icpc|icpx]
opt_compiler = g++
# define Long (array index type) as 32 or 64 bit integer
opt_long32 = true
# debug mode
opt_debug = true
# address sanitizer (only for g++ dynamic debug build)
opt_asan = $(opt_debug)
# c++ standard [c++11|gnu++11]
opt_std = c++11
# static link (not all libs supported)
opt_static = false
# minimum build (all below options set to false)
opt_min = false
# use quad precision float (`__float128` extension of gcc)
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
# define _Float128
# (only needed for centos7.9 `scl enable devtoolset-9 bash`, and clang++)
opt_no__Float128 = false
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

ifneq ($(opt_compiler), g++)
    opt_quadmath = false
    opt_mplapack = false
endif

# === Debug / Release ===
ifeq ($(opt_debug), true)
    $(info Build: Debug)
    debug_flag = -g
    ifeq ($(opt_compiler), g++)
        debug_flag = -g -ftrapv $(asan_flag)
    endif
else
    $(info Build: Release)
    release_flag = -O3 -D NDEBUG
endif

# Address Sanitizer
ifeq ($(opt_asan), true)
    ifeq ($(opt_compiler), g++)
        ifeq ($(opt_static), false)
            $(info Address Sanitizer: on)
            asan_flag = -fsanitize=address -static-libasan -D SLS_USE_ASAN
        else
            $(info Address Sanitizer: off)
        endif
    else
        $(info Address Sanitizer: off)
    endif
else
    $(info Address Sanitizer: off)
endif

# === 64bit index ===
ifeq ($(opt_long32), true)
    $(info Long bits: 32)
    long_flag = -D SLS_USE_INT_AS_LONG
else
    $(info Long bits: 64)
endif

ifeq ($(opt_lapack), none)
    $(info CBLAS/LAPACKE: off)
endif

ifeq ($(opt_lapack), reference)
    $(info CBLAS/LAPACKE: reference)
# === CBLAS (reference) ===
    cblas_flag = -D SLS_USE_CBLAS
    ifeq ($(opt_long32), false)
        cblas_lib = -l cblas64 -l blas64 -l gfortran -l quadmath
    else
        cblas_lib = -l cblas -l blas -l gfortran -l quadmath
    endif
# === LAPACKE (reference) ===
    lapacke_flag = -D SLS_USE_LAPACKE
    ifeq ($(opt_long32), false)
        lapacke_lib = -l lapacke64 -l lapack64
    else
        lapacke_lib = -l lapacke -l lapack
    endif
endif

ifeq ($(opt_lapack), openblas)
    $(info CBLAS/LAPACKE: openblas)
# === CBLAS (openblas) ===
    cblas_flag = -D SLS_USE_CBLAS -I /opt/OpenBLAS/include
    cblas_lib = -l openblas
# === LAPACKE (openblas) ===
    lapacke_flag = -D SLS_USE_LAPACKE
endif

# === MKL ===
# ref: MKL link advisor https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor
ifeq ($(opt_lapack), mkl)
    $(info  )
    $(info === Intel OneAPI config ===)
    $(info Product: oneMKL 2021)
    $(info OS: Linux)
    $(info Language: C/C++)
    $(info Arch: x86-64)
    $(info Threading: Sequential)
    # Interface: 32bit int
    ifeq ($(opt_long32), true)
        $(info Interface: 32bit int)
        # Compiler: g++
        ifeq ($(opt_compiler), g++)
            $(info Compiler: g++)
            mkl_flag = -D SLS_USE_MKL -m64 -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib = -Wl,--start-group -l:libmkl_intel_lp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -l pthread -l m -l dl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib = -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -l:libmkl_intel_lp64.so -l:libmkl_sequential.so -l:libmkl_core.so -l pthread -l m -l dl
            endif
        endif
        # Compiler: icpc
        ifeq ($(opt_compiler), icpc)
            $(info Compiler: icpc)
            mkl_flag = -D SLS_USE_MKL -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib = -Wl,--start-group -l:libmkl_intel_lp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib = -L${MKLROOT}/lib/intel64 -l:libmkl_intel_lp64.so -l:libmkl_sequential.so -l:libmkl_core.so -l pthread -l m -l dl
            endif
        endif
    # Interface: 64bit int
    else
        $(info Interface: 64bit int)
        # Compiler: g++
        ifeq ($(opt_compiler), g++)
            $(info Compiler: g++)
            mkl_flag = -D SLS_USE_MKL -D MKL_ILP64 -m64 -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib = -Wl,--start-group -l:libmkl_intel_ilp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -l pthread -l m -l dl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib = -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -l mkl_intel_ilp64 -l mkl_sequential -l mkl_core -l pthread -l m -l dl
            endif
        endif
        # Compiler: icpc
        ifeq ($(opt_compiler), icpc)
            $(info Compiler: icpc)
            mkl_flag = -D SLS_USE_MKL -DMKL_ILP64  -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib = -Wl,--start-group -l:libmkl_intel_ilp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib = -L${MKLROOT}/lib/intel64 -l mkl_intel_ilp64 -l mkl_sequential -l mkl_core -l pthread -l m -l dl
            endif
        endif
    endif
    $(info ===========================)
    $(info  )
endif

# === Boost ===
ifeq ($(opt_boost), true)
    boost_flag = -D SLS_USE_BOOST
    ifeq ($(opt_static), false)
        $(info Boost: dynamic)
        boost_lib = -l:libboost_system.so -l:libboost_filesystem.so
    else
        $(info Boost: static)
        boost_lib = -l:libboost_system.a -l:libboost_filesystem.a
    endif
else
    $(info Boost: off)
endif

# === GSL ===
ifeq ($(opt_gsl), true)
    gsl_flag = -D SLS_USE_GSL
    ifeq ($(opt_static), false)
        $(info GSL: dynamic)
        gsl_lib = -l:libgsl.so
    else
        $(info GSL: static)
        gsl_lib = -l:libgsl.a
    endif
else
    $(info GSL: off)
endif

# === Eigen ===
ifeq ($(opt_eigen), true)
    $(info Eigen: on)
    eigen_flag = -D SLS_USE_EIGEN
else
    $(info Eigen: off)
endif

# === Quad Math ===
# only supports g++
ifeq ($(opt_quadmath), true)
    $(info Quad Math: on)
    quad_math_flag = -D SLS_USE_QUAD_MATH -fext-numeric-literals
    quad_math_lib = -l quadmath
else
    $(info Quad Math: off)
endif

# === Arb ===
ifeq ($(opt_arb), true)
    arb_flag = -D SLS_USE_ARB
    ifeq ($(opt_static), false)
        $(info Arb: dynamic)
        # use -larb if compiled from source, or create soft link named flint-arb
        arb_lib = -l:libflint-arb.so -l:libflint.so -l:libmpfr.so -l:libgmp.so 
    else
        $(info Arb: static)
        arb_lib = -l:libflint-arb.a -l:libflint.a -l:libmpfr.a -l:libgmp.a 
    endif
else
    $(info Arb: off)
endif

# === MPLAPACK ===
ifeq ($(opt_mplapack), true)
    mplapack_flag = -D SLS_USE_MPLAPACK
    ifeq ($(opt_static), false)
        $(info MPLAPACK: dynamic)
        mplapack_lib = -l:libmplapack__Float128.so -l:libmpblas__Float128.so
    else
        $(info MPLAPACK: static)
        mplapack_lib = -l:libmplapack__Float128.a -l:libmpblas__Float128.a
    endif
else
    $(info MPLAPACK: off)
endif

# === Arpack ===
ifeq ($(opt_arpack), true)
    ifeq ($(opt_lapack), reference)
        arpack_flag = -D SLS_USE_ARPACK
        ifeq ($(opt_static), false)
            $(info Arpack: dynamic)
            ifeq ($(opt_long32), true)
                arpack_lib = -l:libarpack.so -l:liblapack.so -l:libblas.so -l:libgfortran.so
            else
                arpack_lib = -l:libarpack64.so -l:liblapack64.so -l:libblas64.so -l:libgfortran.so
            endif
        else
            $(info Arpack: static)
            ifeq ($(opt_long32), true)
                arpack_lib = -l:libarpack.a -l:liblapack.a -l:libblas.a -l:libgfortran.a
            else
                arpack_lib = -l:libarpack64.a -l:liblapack64.a -l:libblas64.a -l:libgfortran.a
            endif
        endif
    else
        $(info Arpack: off)
    endif
else
    $(info Arpack: off)
endif

# === SQLite ===
ifeq ($(opt_sqlite), true)
    sqlite_flag = -D SLS_USE_SQLITE
    ifeq ($(opt_static), false)
        $(info SQLite: dynamic)
        sqlite_lib = -l:libsqlite3.so
    else
        $(info SQLite: static)
        sqlite_lib = -l:libsqlite3.a
    endif
else
    $(info SQLite: off)
endif

# === Matlab .mat file ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
ifeq ($(opt_matfile), true)
    ifeq ($(opt_static), false)
        $(info Using Matlab .mat (dynamic))
        matfile_bin_path = ../MatFile_linux/lib
        matfile_flag = -D SLS_USE_MATFILE -I ../MatFile_linux/include
        matfile_lib = -Wl,-rpath,$(matfile_bin_path) -L $(matfile_bin_path) -l mat -l mx
    else
        $(info Matlab .mat: off)
    endif
else
    $(info Matlab .mat: off)
endif

# need to define _Float128
ifeq ($(opt_no__Float128), true)
    $(info will add _Float128)
    def__Float128 = -D SLS_NO__Float128
endif

# === compiler flags ===
ifeq ($(opt_compiler), g++)
    compiler_flag = -std=$(opt_std) -Wall -Wno-cpp -Wno-reorder -Wno-misleading-indentation -fmax-errors=20 -fopenmp
endif
ifeq ($(opt_compiler), clang++)
    compiler_flag = -std=$(opt_std) -Wall -Wno-reorder -Wno-misleading-indentation -Wno-overloaded-virtual -ferror-limit=20
endif
ifeq ($(opt_compiler), icpc)
    compiler_flag = -std=$(opt_std) -Wall -fp-model precise -fp-model except -qopenmp -Qoption,cpp,--extended_float_type
endif
ifeq ($(opt_compiler), icpx)
    compiler_flag = -std=$(opt_std) -Wall -fp-model precise -qopenmp -Qoption,cpp,--extended_float_types -Wno-reorder-ctor -Wno-overloaded-virtual
endif

$(info  )$(info  )$(info  )$(info  )
# ---------------------------------------------------------

# all flags
flags = $(compiler_flag) $(debug_flag) $(release_flag) $(mkl_flag) $(cblas_flag) $(lapacke_flag)  $(arpack_flag)  $(boost_flag) $(gsl_flag) $(arb_flag) $(quad_math_flag) $(eigen_flag) $(matfile_flag) $(sqlite_flag) $(long_flag) $(mplapack_flag) $(def__Float128)
# -pedantic # show more warnings

# all libs
ifeq ($(opt_static), true)
    static_flag = -static
endif
libs = $(static_flag) $(arpack_lib) $(mplapack_lib) $(gsl_lib) $(mkl_lib) $(lapacke_lib) $(cblas_lib) $(arb_lib) $(boost_lib) $(matfile_lib) $(sqlite_lib) $(quad_math_lib)

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
