test_disjoint_sets.o: test/test_disjoint_sets.cpp \
 make/deps/test_disjoint_sets.cpp.mak test/../SLISC/algo/disjoint_sets.h \
 test/../SLISC/algo/../global.h test/../SLISC/algo/../config.h \
 test/../SLISC/algo/../prec/quad_math_declare.h \
 test/../SLISC/algo/../prec/quad_math.h test/../SLISC/util/random.h \
 test/../SLISC/util/../arith/arith2.h \
 test/../SLISC/util/../arith/../arith/scalar_arith.h \
 test/../SLISC/util/../arith/../arith/../arith/complex_arith.h \
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
 test/../SLISC/util/../arith/../arith/../dense/Jcmat3.h
	$(opt_compiler) $(flags) -c test/test_disjoint_sets.cpp
