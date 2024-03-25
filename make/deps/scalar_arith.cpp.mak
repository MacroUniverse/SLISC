# this file is auto generated with Makefile and g++
tests/scalar_arith.o: tests/scalar_arith.cpp \
 tests/../SLISC/arith/scalar_arith.h \
 tests/../SLISC/arith/../arith/fp_arith.h \
 tests/../SLISC/arith/../arith/../util/bit.h \
 tests/../SLISC/arith/../arith/../util/../global.h \
 tests/../SLISC/arith/../arith/../util/../config.h \
 tests/../SLISC/arith/../arith/../util/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../arith/../util/../prec/quad_math.h \
 tests/../SLISC/arith/../arith/complex_arith.h \
 tests/../SLISC/arith/../arith/Imag.h tests/../SLISC/util/STL_util.h
	$(opt_compiler) $(all_flags) -c tests/scalar_arith.cpp -o tests/scalar_arith.o
