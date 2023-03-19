test_Imag.o: test/test_Imag.cpp make/deps/test_Imag.cpp.mak \
 test/../SLISC/arith/Imag.h test/../SLISC/arith/../global.h \
 test/../SLISC/arith/../config.h \
 test/../SLISC/arith/../prec/quad_math_declare.h \
 test/../SLISC/arith/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_Imag.cpp
