test_input.o: test/test_input.cpp make/deps/test_input.cpp.mak \
 test/../SLISC/util/input.h test/../SLISC/util/../global.h \
 test/../SLISC/util/../config.h \
 test/../SLISC/util/../prec/quad_math_declare.h \
 test/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_input.cpp
