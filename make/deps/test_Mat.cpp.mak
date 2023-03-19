test_Mat.o: test/test_Mat.cpp make/deps/test_Mat.cpp.mak \
 test/../SLISC/dense/Mat.h test/../SLISC/dense/../dense/Vbase.h \
 test/../SLISC/dense/../dense/../global.h \
 test/../SLISC/dense/../dense/../config.h \
 test/../SLISC/dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/dense/../dense/../prec/quad_math.h \
 test/../SLISC/dense/../dense/../arith/Imag.h \
 test/../SLISC/dense/../dense/../str/str.h
	$(opt_compiler) $(flags) -c test/test_Mat.cpp
