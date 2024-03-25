# this file is auto generated with Makefile and g++
tests/global.o: tests/global.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/global.cpp -o tests/global.o
