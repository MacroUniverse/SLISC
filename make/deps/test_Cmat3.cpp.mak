test_Cmat3.o: test/test_Cmat3.cpp make/deps/test_Cmat3.cpp.mak \
 test/../SLISC/dense/Cmat3.h test/../SLISC/dense/../dense/Vbase.h \
 test/../SLISC/dense/../dense/../global.h \
 test/../SLISC/dense/../dense/../config.h \
 test/../SLISC/dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/dense/../dense/../prec/quad_math.h \
 test/../SLISC/dense/../dense/../arith/Imag.h \
 test/../SLISC/dense/../dense/../str/str.h
	$(opt_compiler) $(flags) -c test/test_Cmat3.cpp
