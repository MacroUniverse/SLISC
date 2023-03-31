test_Cmat.o: tests/test_Cmat.cpp tests/../SLISC/arith/compare.h \
 tests/../SLISC/arith/../dense/Vec.h \
 tests/../SLISC/arith/../dense/../dense/Vbase.h \
 tests/../SLISC/arith/../dense/../dense/../global.h \
 tests/../SLISC/arith/../dense/../dense/../config.h \
 tests/../SLISC/arith/../dense/../dense/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../dense/../dense/../prec/quad_math.h \
 tests/../SLISC/arith/../dense/../dense/../arith/Imag.h \
 tests/../SLISC/arith/../dense/../dense/../str/str.h \
 tests/../SLISC/arith/../dense/Mat.h tests/../SLISC/arith/../dense/Mat3.h \
 tests/../SLISC/arith/../dense/Cmat.h \
 tests/../SLISC/arith/../dense/Cmat3.h \
 tests/../SLISC/arith/../dense/Cmat4.h \
 tests/../SLISC/arith/../sparse/Cband.h \
 tests/../SLISC/arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/arith/../sparse/Mcoo.h \
 tests/../SLISC/arith/../sparse/Cmobd.h \
 tests/../SLISC/arith/../sparse/../arith/scalar_arith.h \
 tests/../SLISC/arith/../sparse/../arith/../arith/complex_arith.h \
 tests/../SLISC/arith/../dense/Svec.h \
 tests/../SLISC/arith/../dense/Scmat.h \
 tests/../SLISC/arith/../dense/Scmat3.h \
 tests/../SLISC/arith/../dense/Jcmat3.h tests/../SLISC/util/random.h \
 tests/../SLISC/util/../arith/arith2.h \
 tests/../SLISC/util/../util/STL_util.h
	$(opt_compiler) $(flags) -c tests/test_Cmat.cpp
