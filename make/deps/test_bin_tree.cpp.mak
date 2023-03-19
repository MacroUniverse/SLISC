test_bin_tree.o: tests/test_bin_tree.cpp tests/../SLISC/algo/bin_tree.h \
 tests/../SLISC/algo/../global.h tests/../SLISC/algo/../config.h \
 tests/../SLISC/algo/../prec/quad_math_declare.h \
 tests/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_bin_tree.cpp
