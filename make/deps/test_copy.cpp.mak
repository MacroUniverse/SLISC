test_copy.o: tests/test_copy.cpp tests/../SLISC/arith/copy.h \
 tests/../SLISC/arith/../arith/compare.h \
 tests/../SLISC/arith/../arith/../dense/Vec.h \
 tests/../SLISC/arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../global.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../config.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../prec/quad_math.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../arith/Imag.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/arith/../arith/../dense/Mat.h \
 tests/../SLISC/arith/../arith/../dense/Mat3.h \
 tests/../SLISC/arith/../arith/../dense/Cmat.h \
 tests/../SLISC/arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/arith/../arith/../sparse/Cband.h \
 tests/../SLISC/arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/arith/../arith/../sparse/../arith/scalar_arith.h \
 tests/../SLISC/arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 tests/../SLISC/arith/../arith/../dense/Svec.h \
 tests/../SLISC/arith/../arith/../dense/Scmat.h \
 tests/../SLISC/arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/arith/../dense/cut.h tests/../SLISC/arith/arith2.h
	$(opt_compiler) $(flags) -c tests/test_copy.cpp