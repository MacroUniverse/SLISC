# this file is auto generated with Makefile and g++
tests/legendreP.o: tests/legendreP.cpp tests/../SLISC/spec/legendreP.h \
 tests/../SLISC/spec/../arith/scalar_arith.h \
 tests/../SLISC/spec/../arith/../arith/fp_arith.h \
 tests/../SLISC/spec/../arith/../arith/../util/bit.h \
 tests/../SLISC/spec/../arith/../arith/../util/../global.h \
 tests/../SLISC/spec/../arith/../arith/../util/../config.h \
 tests/../SLISC/spec/../arith/../arith/../util/../prec/quad_math_declare.h \
 tests/../SLISC/spec/../arith/../arith/../util/../prec/quad_math.h \
 tests/../SLISC/spec/../arith/../arith/complex_arith.h \
 tests/../SLISC/spec/../arith/../arith/Imag.h
	$(opt_compiler) $(all_flags) -c tests/legendreP.cpp -o tests/legendreP.o
