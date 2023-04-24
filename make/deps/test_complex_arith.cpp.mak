# this file is auto generated with Makefile and g++
test_complex_arith.o: tests/test_complex_arith.cpp \
 tests/../SLISC/arith/complex_arith.h tests/../SLISC/arith/../global.h \
 tests/../SLISC/arith/../config.h \
 tests/../SLISC/arith/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_complex_arith.cpp
