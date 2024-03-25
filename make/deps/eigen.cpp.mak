# this file is auto generated with Makefile and g++
tests/eigen.o: tests/eigen.cpp tests/../SLISC/global.h \
 tests/../SLISC/config.h tests/../SLISC/prec/quad_math_declare.h \
 tests/../SLISC/prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/eigen.cpp -o tests/eigen.o
