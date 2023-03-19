test_bit.o: test/test_bit.cpp make/deps/test_bit.cpp.mak \
 test/../SLISC/util/bit.h test/../SLISC/util/../global.h \
 test/../SLISC/util/../config.h \
 test/../SLISC/util/../prec/quad_math_declare.h \
 test/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_bit.cpp
