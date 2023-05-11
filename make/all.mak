# use g++ with libraries
# requires g++8.3 or higher
# any change in *.h.in file will cause all *.cpp files to compile

#======== options =========
# compiler [g++|clang++|icpc|icpx]
opt_compiler := g++
# define Long (array index type) as 32 or 64 bit integer
opt_long32 := true
# debug mode
opt_debug := true
# address sanitizer (only for g++ dynamic debug build)
opt_asan := $(opt_debug)
# c++ standard e.g. c++11, gnu++11, c++20
opt_std := c++11
# static link (not all libs supported)
opt_static := false
# minimum build (all below options set to false)
opt_min := false
# verbose output for Octave debug
opt_verb := false
# compile all tests as main.x or into individual tests/*.x
opt_main := false
# use quad precision float (`__float128` extension of gcc)
opt_quadmath := false
# lapack package (reference, openblas, mkl, none)
opt_lapack := reference
# use MPLAPACK lib
opt_mplapack := $(opt_quadmath)
# use Boost lib
opt_boost := true
# use GSL lib
opt_gsl := true
# use Eigen lib
opt_eigen := true
# use Arblib lib
opt_arb := true
# use Arpack++2 lib
opt_arpack := true
# use sqlite
opt_sqlite := false
# use SQLiteCpp
opt_sqlitecpp := true
# read and write Matlab .mat file
opt_matfile := false
#==========================

# === minimum build ===
ifeq ($(opt_min), true)
    opt_quadmath := false
    opt_mplapack := false
    opt_lapack := none
    opt_boost := false
    opt_gsl := false
    opt_eigen := false
    opt_arb := false
    opt_arpack := false
    opt_sqlite := false
    opt_matfile := false
endif

ifneq ($(opt_compiler), g++)
    opt_quadmath := false
    opt_mplapack := false
endif

SHELL := /bin/bash

red := \033[1;31m

green := \033[1;32m

yellow := \033[1;33m

normal := \033[0m

$(info ) $(info ) $(info ) $(info ) $(info ) $(info )

tmp := $(shell echo "// this file is auto generated by Makefile/CMake" > SLISC/config.h.new)

ifeq ($(opt_static), true)
    static_flag := -static
else
    static_flag :=
endif

define = \#define

# === Debug / Release ===
ifeq ($(opt_debug), true)
    $(info Build: Debug)
    tmp := $(shell echo "$(define) SLS_CHECK_BOUNDS" >> SLISC/config.h.new)
    tmp := $(shell echo "$(define) SLS_CHECK_SHAPES" >> SLISC/config.h.new)
    debug_flag := -g
    release_flag :=
    ifeq ($(opt_compiler), g++)
        debug_flag := -g -ftrapv $(asan_flag) # -pedantic # show more warnings
    endif
else
    $(info Build: Release)
    tmp := $(shell echo "$(define) NDEBUG" >> SLISC/config.h.new)
    release_flag := -O3
    debug_flag :=
endif

# === main.x ===
ifeq ($(opt_main), true)
    $(info main.x: on)
    tmp := $(shell echo "$(define) SLS_TEST_ALL" >> SLISC/config.h.new)
else
    $(info main.x: off)
endif

# Address Sanitizer
ifeq ($(opt_asan), true)
    ifeq ($(opt_compiler), g++)
        ifeq ($(opt_static), false)
            $(info Address Sanitizer: on)
            asan_flag := -fsanitize=address -static-libasan
            tmp := $(shell echo "$(define) SLS_USE_ASAN" >> SLISC/config.h.new)
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
    tmp := $(shell echo "$(define) SLS_USE_INT_AS_LONG" >> SLISC/config.h.new)
else
    $(info Long bits: 64)
endif

ifeq ($(opt_lapack), none)
    $(info CBLAS/LAPACKE: off)
endif

cblas_lib :=
lapacke_lib :=
ifeq ($(opt_lapack), reference)
# === CBLAS (reference) ===
    tmp := $(shell echo "$(define) SLS_USE_CBLAS" >> SLISC/config.h.new)
    ifeq ($(opt_long32), false)
        $(info CBLAS: ref64)
        cblas_lib := -l cblas64 -l blas64 -l gfortran
    else
        $(info CBLAS: ref32)
        cblas_lib := -l cblas -l blas -l gfortran
    endif
# === LAPACKE (reference) ===
    tmp := $(shell echo "$(define) SLS_USE_LAPACKE" >> SLISC/config.h.new)
    ifeq ($(opt_long32), false)
        $(info LAPACKE: ref64)
        lapacke_lib := -l lapacke64 -l lapack64
    else
        $(info LAPACKE: ref32)
        lapacke_lib := -l lapacke -l lapack
    endif
endif

ifeq ($(opt_lapack), openblas)
    $(info CBLAS/LAPACKE: openblas)
# === CBLAS (openblas) ===
    tmp := $(shell echo "$(define) SLS_USE_CBLAS" >> SLISC/config.h.new)
    cblas_lib := -l openblas
# === LAPACKE (openblas) ===
    tmp := $(shell echo "$(define) SLS_USE_LAPACKE" >> SLISC/config.h.new)
endif

# === MKL ===
# ref: MKL link advisor https://software.intel.com/en-us/articles/intel-mkl-link-line-advisor
mkl_flag :=
mkl_lib :=
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
            tmp := $(shell echo "$(define) SLS_USE_MKL" >> SLISC/config.h.new)
            mkl_flag := -m64 # -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib := -Wl,--start-group -l:libmkl_intel_lp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -l pthread -l m -l dl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib := -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -l:libmkl_intel_lp64.so -l:libmkl_sequential.so -l:libmkl_core.so -l pthread -l m -l dl
            endif
        endif
        # Compiler: icpc
        ifeq ($(opt_compiler), icpc)
            $(info Compiler: icpc)
            tmp := $(shell echo "$(define) SLS_USE_MKL" >> SLISC/config.h.new)
            mkl_flag := # -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib := -Wl,--start-group -l:libmkl_intel_lp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib := -L${MKLROOT}/lib/intel64 -l:libmkl_intel_lp64.so -l:libmkl_sequential.so -l:libmkl_core.so -l pthread -l m -l dl
            endif
        endif
    # Interface: 64bit int
    else
        $(info Interface: 64bit int)
        # Compiler: g++
        ifeq ($(opt_compiler), g++)
            $(info Compiler: g++)
            tmp := $(shell echo "$(define) SLS_USE_MKL" >> SLISC/config.h.new)
            tmp := $(shell echo "$(define) MKL_ILP64" >> SLISC/config.h.new)
            mkl_flag := -m64 # -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib := -Wl,--start-group -l:libmkl_intel_ilp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -l pthread -l m -l dl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib := -L${MKLROOT}/lib/intel64 -Wl,--no-as-needed -l mkl_intel_ilp64 -l mkl_sequential -l mkl_core -l pthread -l m -l dl
            endif
        endif
        # Compiler: icpc
        ifeq ($(opt_compiler), icpc)
            $(info Compiler: icpc)
            tmp := $(shell echo "$(define) SLS_USE_MKL" >> SLISC/config.h.new)
            tmp := $(shell echo "$(define) MKL_ILP64" >> SLISC/config.h.new)
            mkl_flag := # -I "${MKLROOT}/include"
            # static link
            ifeq ($(opt_static), true)
                $(info Link: static)
                mkl_lib := -Wl,--start-group -l:libmkl_intel_ilp64.a -l:libmkl_sequential.a -l:libmkl_core.a -Wl,--end-group -lpthread -lm -ldl
            # dynamic link
            else
                $(info Link: dynamic)
                mkl_lib := -L${MKLROOT}/lib/intel64 -l mkl_intel_ilp64 -l mkl_sequential -l mkl_core -l pthread -l m -l dl
            endif
        endif
    endif
    $(info ===========================)
    $(info  )
endif

# === Boost ===
ifeq ($(opt_boost), true)
    tmp := $(shell echo "$(define) SLS_USE_BOOST" >> SLISC/config.h.new)
    ifeq ($(opt_static), false)
        $(info Boost: dynamic)
        boost_lib := -l:libboost_system.so -l:libboost_filesystem.so
    else
        $(info Boost: static)
        boost_lib := -l:libboost_system.a -l:libboost_filesystem.a
    endif
else
    $(info Boost: off)
    boost_lib :=
endif

# === GSL ===
ifeq ($(opt_gsl), true)
    tmp := $(shell echo "$(define) SLS_USE_GSL" >> SLISC/config.h.new)
    ifeq ($(opt_static), false)
        $(info GSL: dynamic)
        gsl_lib := -l:libgsl.so
    else
        $(info GSL: static)
        gsl_lib := -l:libgsl.a
    endif
else
    $(info GSL: off)
    gsl_lib :=
endif

# === Eigen ===
ifeq ($(opt_eigen), true)
    $(info Eigen: on)
    tmp := $(shell echo "$(define) SLS_USE_EIGEN" >> SLISC/config.h.new)
else
    $(info Eigen: off)
endif

# === Quad Math ===
# only supports g++
ifeq ($(opt_quadmath), true)
    $(info Quad Math: on)
    tmp := $(shell echo "$(define) SLS_USE_QUAD_MATH" >> SLISC/config.h.new)
    quad_math_flag := -fext-numeric-literals
    quad_math_lib := -l quadmath
else
    $(info Quad Math: off)
    quad_math_flag :=
endif

# === Arb ===
ifeq ($(opt_arb), true)
    tmp := $(shell echo "$(define) SLS_USE_ARB" >> SLISC/config.h.new)
    ifeq ($(opt_static), false)
        $(info Arb: dynamic)
        # use -larb if compiled from source, or create soft link named flint-arb
        arb_lib := -l:libflint-arb.so -l:libflint.so -l:libmpfr.so -l:libgmp.so 
    else
        $(info Arb: static)
        arb_lib := -l:libflint-arb.a -l:libflint.a -l:libmpfr.a -l:libgmp.a 
    endif
else
    $(info Arb: off)
    arb_lib :=
endif

# === MPLAPACK ===
ifeq ($(opt_mplapack), true)
    tmp := $(shell echo "$(define) SLS_USE_MPLAPACK" >> SLISC/config.h.new)
    ifeq ($(opt_static), false)
        $(info MPLAPACK: dynamic)
        mplapack_lib := -l:libmplapack__Float128.so -l:libmpblas__Float128.so
    else
        $(info MPLAPACK: static)
        mplapack_lib := -l:libmplapack__Float128.a -l:libmpblas__Float128.a
    endif
else
    $(info MPLAPACK: off)
    mplapack_lib :=
endif

# === Arpack ===
arpack_lib :=
ifeq ($(opt_arpack), true)
    ifeq ($(opt_lapack), reference)
        tmp := $(shell echo "$(define) SLS_USE_ARPACK" >> SLISC/config.h.new)
        ifeq ($(opt_static), false)
            $(info Arpack: dynamic)
            ifeq ($(opt_long32), true)
                arpack_lib := -l:libarpack.so -l:liblapack.so -l:libblas.so -l:libgfortran.so
            else
                arpack_lib := -l:libarpack64.so -l:liblapack64.so -l:libblas64.so -l:libgfortran.so
            endif
        else
            $(info Arpack: static)
            ifeq ($(opt_long32), true)
                arpack_lib := -l:libarpack.a -l:liblapack.a -l:libblas.a -l:libgfortran.a
            else
                arpack_lib := -l:libarpack64.a -l:liblapack64.a -l:libblas64.a -l:libgfortran.a
            endif
        endif
    else
        $(info Arpack: off)
    endif
else
    $(info Arpack: off)
endif

# === SQLiteCpp ===
ifeq ($(opt_sqlitecpp), true)
    opt_sqlite := false
    tmp := $(shell echo "$(define) SLS_USE_SQLITECPP" >> SLISC/config.h.new)
    tmp := $(shell echo "$(define) SLS_USE_SQLITE" >> SLISC/config.h.new)
    $(info SQLiteCpp: static)
    sqlitecpp_lib := -l:libSQLiteCpp.a -l:libSQLiteCpp-sqlite3.a -l pthread -l dl
else
    $(info SQLiteCpp: off)
    sqlitecpp_lib :=
endif

# === SQLite ===
ifeq ($(opt_sqlite), true)
    tmp := $(shell echo "$(define) SLS_USE_SQLITE" >> SLISC/config.h.new)
    ifeq ($(opt_static), false)
        $(info SQLite: dynamic)
        sqlite_lib := -l:libsqlite3.so
    else
        $(info SQLite: static)
        sqlite_lib := -l:libsqlite3.a
    endif
else
    $(info SQLite: off)
    sqlite_lib :=
endif

# === Matlab .mat file ===
# (conflicts with boost_filesystem.so other than version 1.56.0)
matfile_lib =
ifeq ($(opt_matfile), true)
    ifeq ($(opt_static), false)
        $(info Using Matlab .mat (dynamic))
        tmp := $(shell echo "$(define) SLS_USE_MATFILE" >> SLISC/config.h.new)
        matfile_lib := -l mat -l mx
    else
        $(info Matlab .mat: off)
    endif
else
    $(info Matlab .mat: off)
endif

# =========== Done with Libs ===========

tmp := $(shell echo "$(define) SLS_FP_EXCEPT" >> SLISC/config.h.new)
tmp := $(shell echo "$(define) SLS_USE_UTFCPP" >> SLISC/config.h.new)

# config.h's modification time won't change if content not changed
$(info  )

tmp := $(shell \
    if cmp -s SLISC/config.h.new SLISC/config.h; then \
        rm -f SLISC/config.h.new; \
        echo "config.h is the same."; \
    else \
        mv SLISC/config.h.new SLISC/config.h; \
        echo "config.h has changed."; \
    fi \
)
$(info $(tmp));

# === compiler flags ===
ifeq ($(opt_compiler), g++)
    compiler_flag := -std=$(opt_std) -Wall -Wno-reorder -fmax-errors=5 -fopenmp # -ffast-math (includin -fno-math-errno, -funsafe-math-optimizations, -fno-signed-zeros, -fno-trapping-math, -ffinite-math-only)
endif

ifeq ($(opt_compiler), clang++)
    compiler_flag := -std=$(opt_std) -Wall -Wno-overloaded-virtual -ferror-limit=5 -fopenmp # -ffast-math
endif
ifeq ($(opt_compiler), icpc)
    compiler_flag := -std=$(opt_std) -Wall -fp-model precise -fp-model except -qopenmp -Qoption,cpp,--extended_float_type
endif
ifeq ($(opt_compiler), icpx)
    compiler_flag := -std=$(opt_std) -Wall -fp-model precise -qopenmp -Qoption,cpp,--extended_float_types -Wno-reorder-ctor -Wno-overloaded-virtual
endif

$(info  )$(info  )$(info  )$(info  )
# ---------------------------------------------------------

# all flags
all_flags := $(compiler_flag) $(debug_flag) $(release_flag) $(mkl_flag) $(quad_math_flag)

# all libs
libs := $(static_flag) $(arpack_lib) $(mplapack_lib) $(gsl_lib) $(mkl_lib) $(lapacke_lib) $(cblas_lib) $(arb_lib) $(boost_lib) $(matfile_lib) $(sqlite_lib) $(sqlitecpp_lib) $(quad_math_lib)

# subfolders of SLISC, including SLISC, e.g. "SLISC/:SLISC/prec/:...:SLISC/lin/"
in_paths := $(shell find SLISC -maxdepth 1 -type d -printf "../%p/:" | head -c -2)/

# === File Lists ===
path_test_cpp := $(shell ls tests/*.cpp) # tests/*.cpp
path_cpp_mak := $(addsuffix .mak, $(subst tests/, make/deps/, $(path_test_cpp)))
path_test_o := $(path_test_cpp:.cpp=.o) # tests/*.o
path_test_x := $(path_test_cpp:.cpp=.x) # tests/*.o
path_header_in := $(shell ls SLISC/*/*.h.in) # SLISC/*/*.h.in
path_gen_headers := $(path_header_in:.h.in=.h) # generated headers in SLISC/
path_cur_headers := $(shell ls SLISC/*.h) $(shell ls SLISC/*/*.h) # current headers in SLISC/, including hand written ones
path_headers := $(sort $(path_gen_headers) $(path_cur_headers)) # all headers
path_nogen_headers := $(filter-out $(path_headers),$(path_gen_headers)) # non-generated headers

# number of cpu
Ncpu := $(shell getconf _NPROCESSORS_ONLN)


##################### RULES ##########################

# remake all and test all
all:
	make test64
	make test64q
	make test

ifeq ($(opt_main), false)

    # use `make test*` without any options! will ignore.
    test: clean_all
		$(info remake and run all tests - default)
		@make h
		@make depend -j$(Ncpu)
		@make $(path_test_x) -j$(Ncpu)
		@printf "\n\n\n"
		@make run_test_x
		@printf "\n\n\n"

    test64: clean_all
		$(info remake and run all tests - 64bit)
		@make h64
		@make opt_long32=false depend -j$(Ncpu)
		@make opt_long32=false $(path_test_x) -j$(Ncpu)
		@printf "\n\n\n"
		@make run_test_x
		@printf "\n\n\n"

    test64q: clean_all
		$(info remake and run all tests - 64bit & quadmath)
		@make h64q
		@make opt_long32=false opt_quadmath=true depend -j$(Ncpu)
		@make opt_long32=false opt_quadmath=true $(path_test_x) -j$(Ncpu)
		@printf "\n\n\n"
		@make run_test_x
		@printf "\n\n\n"

    run_test_x:
		@for x in ${path_test_x}; do \
			echo $${x}; ./$${x} < input.inp; \
			if [ $$? -ne 0 ]; then \
				printf "returned non-zero! \n\n"; \
				failed=1; \
				break; \
			fi \
		done; \
		if [ -n "$$failed" ]; then \
			false; \
		else \
			printf "\nall tests successful!\n"; \
		fi

else # opt_main == false

    # use `make test*` without any option! options will ignore.
    test: clean_all
		$(info remake and run all tests - default)
		@make h
		@make depend -j$(Ncpu)
		@make main.x -j$(Ncpu)
		@printf "\n\n\n"
		./main.x < input.inp
		@printf "\n\n\n"

    test64: clean_all
		$(info remake and run all tests - 64bit)
		@make h64
		@make opt_long32=false depend -j$(Ncpu)
		@make opt_long32=false main.x -j$(Ncpu)
		@printf "\n\n\n"
		./main.x < input.inp
		@printf "\n\n\n"

    test64q: clean_all
		$(info remake and run all tests - 64bit & quadmath)
		@make h64q
		@make opt_long32=false opt_quadmath=true depend -j$(Ncpu)
		@make opt_long32=false opt_quadmath=true main.x -j$(Ncpu)
		@printf "\n\n\n"
		./main.x < input.inp
		@printf "\n\n\n"

endif # opt_main


ifeq ($(opt_main), true)
    main.x: main.o $(path_test_o)
		$(opt_compiler) $(all_flags) -o main.x main.o tests/*.o $(libs)

    main.o: main.cpp tests/test_all.h
		$(opt_compiler) $(all_flags) -c main.cpp
else
    main.x:
		$(error opt_main if off!)
    main.o:
		$(error opt_main if off!)
endif

# [manual] rule files for *.o [make/deps/*.mak]
# use when you change `#include`
depend: $(path_cpp_mak)

# remake all headers
h_all:
	make h64
	make h64q
	make h

h: clean_h
	$(info remake all headers)
	octave --no-window-system --eval "cd preprocessor; auto_gen('$(in_paths)', [], $(opt_quadmath), $(opt_long32), $(opt_verb))"

h64:
	$(info remake all headers - 64bit)
	make opt_long32=false h
	rm -rf SLISC-64
	cp -r SLISC SLISC-64
	find SLISC-64 -name "*.h.in" -delete

h64q:
	$(info remake all headers - 64bit & quad_math)
	make opt_long32=false opt_quadmath=true h
	rm -rf SLISC-64q
	cp -r SLISC SLISC-64q
	find SLISC-64q -name "*.h.in" -delete
	

clean_all: clean clean_h clean_dep

clean:
	rm -f *.o *.x tests/*.o tests/*.x

clean_h:
	rm -f $(path_gen_headers)

clean_dep:
	rm -f make/deps/*

# ======= implicit/generated rules =======
# default target

ifneq ($(opt_main), false)
    tests/%.x:
		$(error opt_main if off!)
else
    tests/%.x: tests/%.o
		@printf "\n$(yellow)$@$(normal):\n"
		$(opt_compiler) $(all_flags) $< -o $@ $(libs)
endif

make/deps/%.cpp.mak: tests/%.cpp
	@echo "# this file is auto generated with Makefile and g++" > $@
	g++ -MM -MT $(patsubst %.cpp,%.o,$<) $< >> $@
	@echo "	\$$(opt_compiler) \$$(all_flags) -c $< -o $(patsubst %.cpp,%.o,$<)" >> $@

# rules for tests/*.o

-include make/deps/*.mak

# header generation with octave
%.h: %.h.in # code gen
	@printf "\n$(green)$@$(normal):\n"
	octave --no-window-system --eval "cd preprocessor; auto_gen('$(in_paths)', '$$(basename $<)', $(opt_quadmath), $(opt_long32), $(opt_verb))"
