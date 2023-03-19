test_huffman.o: tests/test_huffman.cpp tests/../SLISC/algo/huffman.h \
 tests/../SLISC/algo/../global.h tests/../SLISC/algo/../config.h \
 tests/../SLISC/algo/../prec/quad_math_declare.h \
 tests/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_huffman.cpp
