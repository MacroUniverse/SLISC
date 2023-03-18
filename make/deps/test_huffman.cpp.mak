test_huffman.o: test/test_huffman.cpp test/../SLISC/algo/huffman.h \
 test/../SLISC/algo/../global.h test/../SLISC/algo/../config.h \
 test/../SLISC/algo/../prec/quad_math_declare.h \
 test/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
