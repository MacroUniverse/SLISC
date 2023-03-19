test_random.o: test/test_random.cpp make/deps/test_random.cpp.mak \
 test/../SLISC/util/random.h test/../SLISC/util/../arith/arith2.h \
 test/../SLISC/util/../arith/../arith/scalar_arith.h \
 test/../SLISC/util/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/util/../arith/../arith/../arith/../global.h \
 test/../SLISC/util/../arith/../arith/../arith/../config.h \
 test/../SLISC/util/../arith/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/util/../arith/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/util/../arith/../arith/../arith/Imag.h \
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
 test/../SLISC/util/../arith/../arith/../dense/Svec.h \
 test/../SLISC/util/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/util/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/util/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/algo/search.h test/../SLISC/algo/../arith/arith1.h \
 test/../SLISC/algo/../dense/cut.h
	$(opt_compiler) $(flags) -c test/test_random.cpp
