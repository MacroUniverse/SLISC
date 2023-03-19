test_bin_tree.o: test/test_bin_tree.cpp make/deps/test_bin_tree.cpp.mak \
 test/../SLISC/algo/bin_tree.h test/../SLISC/algo/../global.h \
 test/../SLISC/algo/../config.h \
 test/../SLISC/algo/../prec/quad_math_declare.h \
 test/../SLISC/algo/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_bin_tree.cpp
