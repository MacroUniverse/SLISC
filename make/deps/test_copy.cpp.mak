test_copy.o: test/test_copy.cpp test/../SLISC/arith/copy.h \
 test/../SLISC/arith/../arith/compare.h \
 test/../SLISC/arith/../arith/../dense/Vec.h \
 test/../SLISC/arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/arith/../arith/../dense/../dense/../global.h \
 test/../SLISC/arith/../arith/../dense/../dense/../config.h \
 test/../SLISC/arith/../arith/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/arith/../arith/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/arith/../arith/../dense/../dense/../arith/Imag.h \
 test/../SLISC/arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/arith/../arith/../dense/Mat.h \
 test/../SLISC/arith/../arith/../dense/Mat3.h \
 test/../SLISC/arith/../arith/../dense/Cmat.h \
 test/../SLISC/arith/../arith/../dense/Cmat3.h \
 test/../SLISC/arith/../arith/../dense/Cmat4.h \
 test/../SLISC/arith/../arith/../sparse/Cband.h \
 test/../SLISC/arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/arith/../arith/../sparse/../arith/scalar_arith.h \
 test/../SLISC/arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 test/../SLISC/arith/../arith/../dense/Svec.h \
 test/../SLISC/arith/../arith/../dense/Scmat.h \
 test/../SLISC/arith/../arith/../dense/Scmat3.h \
 test/../SLISC/arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/arith/../dense/cut.h test/../SLISC/arith/arith2.h
	$(opt_compiler) $(flags) -c $<
