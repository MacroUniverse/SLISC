# this file is auto generated with Makefile and g++
tests/complex_arith.o: tests/complex_arith.cpp \
 tests/../SLISC/arith/complex_arith.h tests/../SLISC/arith/../global.h \
 tests/../SLISC/arith/../config.h \
 tests/../SLISC/arith/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/complex_arith.cpp -o tests/complex_arith.o
