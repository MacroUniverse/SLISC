# this file is auto generated with Makefile and g++
test_legendreP.o: tests/test_legendreP.cpp \
 tests/../SLISC/spec/legendreP.h \
 tests/../SLISC/spec/../arith/scalar_arith.h \
 tests/../SLISC/spec/../arith/../arith/complex_arith.h \
 tests/../SLISC/spec/../arith/../arith/../global.h \
 tests/../SLISC/spec/../arith/../arith/../config.h \
 tests/../SLISC/spec/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/spec/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/spec/../arith/../arith/Imag.h
	$(opt_compiler) $(flags) -c tests/test_legendreP.cpp
