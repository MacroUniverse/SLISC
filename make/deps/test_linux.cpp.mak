test_linux.o: test/test_linux.cpp make/deps/test_linux.cpp.mak \
 test/../SLISC/util/linux.h test/../SLISC/util/../global.h \
 test/../SLISC/util/../config.h \
 test/../SLISC/util/../prec/quad_math_declare.h \
 test/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_linux.cpp
