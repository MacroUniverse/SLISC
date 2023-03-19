test_Vbase.o: test/test_Vbase.cpp make/deps/test_Vbase.cpp.mak \
 test/../SLISC/dense/Vbase.h test/../SLISC/dense/../global.h \
 test/../SLISC/dense/../config.h \
 test/../SLISC/dense/../prec/quad_math_declare.h \
 test/../SLISC/dense/../prec/quad_math.h \
 test/../SLISC/dense/../arith/Imag.h test/../SLISC/dense/../str/str.h
	$(opt_compiler) $(flags) -c test/test_Vbase.cpp
