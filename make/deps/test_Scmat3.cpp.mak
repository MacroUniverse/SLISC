test_Scmat3.o: test/test_Scmat3.cpp make/deps/test_Scmat3.cpp.mak \
 test/../SLISC/dense/Scmat3.h test/../SLISC/dense/../dense/Svec.h \
 test/../SLISC/dense/../dense/../global.h \
 test/../SLISC/dense/../dense/../config.h \
 test/../SLISC/dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/dense/../dense/../prec/quad_math.h \
 test/../SLISC/dense/../dense/../arith/Imag.h test/../SLISC/util/random.h \
 test/../SLISC/util/../arith/arith2.h \
 test/../SLISC/util/../arith/../arith/scalar_arith.h \
 test/../SLISC/util/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/util/../arith/../arith/compare.h \
 test/../SLISC/util/../arith/../arith/../dense/Vec.h \
 test/../SLISC/util/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/util/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/util/../arith/../arith/../dense/Mat.h \
 test/../SLISC/util/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/util/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/util/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/util/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/util/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/util/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/util/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/util/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/util/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/util/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/util/../arith/../arith/../dense/Jcmat3.h
	$(opt_compiler) $(flags) -c test/test_Scmat3.cpp
