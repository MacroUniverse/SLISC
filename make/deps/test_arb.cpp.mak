# this file is auto generated with Makefile and g++
test_arb.o: tests/test_arb.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_arb.cpp
