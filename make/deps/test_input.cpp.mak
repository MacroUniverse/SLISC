# this file is auto generated with Makefile and g++
test_input.o: tests/test_input.cpp tests/../SLISC/util/input.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_input.cpp
