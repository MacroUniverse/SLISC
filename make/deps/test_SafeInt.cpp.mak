# this file is auto generated with Makefile and g++
test_SafeInt.o: tests/test_SafeInt.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h tests/../SLISC/arith/SafeInt.h
	$(opt_compiler) $(flags) -c tests/test_SafeInt.cpp
