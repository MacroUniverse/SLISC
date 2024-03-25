# this file is auto generated with Makefile and g++
tests/huffman.o: tests/huffman.cpp tests/../SLISC/algo/huffman.h \
 tests/../SLISC/algo/../global.h tests/../SLISC/algo/../config.h \
 tests/../SLISC/algo/../prec/quad_math_declare.h \
 tests/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(all_flags) -c tests/huffman.cpp -o tests/huffman.o
