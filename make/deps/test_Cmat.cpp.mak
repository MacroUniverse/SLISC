test_Cmat.o: test/test_Cmat.cpp test/../SLISC/arith/compare.h \
 test/../SLISC/arith/../dense/Vec.h \
 test/../SLISC/arith/../dense/../dense/Vbase.h \
 test/../SLISC/arith/../dense/../dense/../global.h \
 test/../SLISC/arith/../dense/../dense/../config.h \
 test/../SLISC/arith/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/arith/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/arith/../dense/../dense/../arith/Imag.h \
 test/../SLISC/arith/../dense/../dense/../str/str.h \
 test/../SLISC/arith/../dense/Mat.h test/../SLISC/arith/../dense/Mat3.h \
 test/../SLISC/arith/../dense/Cmat.h test/../SLISC/arith/../dense/Cmat3.h \
 test/../SLISC/arith/../dense/Cmat4.h \
 test/../SLISC/arith/../sparse/Cband.h \
 test/../SLISC/arith/../sparse/../dense/Dvec.h \
 test/../SLISC/arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/arith/../sparse/Mcoo.h \
 test/../SLISC/arith/../sparse/Cmobd.h \
 test/../SLISC/arith/../sparse/../arith/scalar_arith.h \
 test/../SLISC/arith/../sparse/../arith/../arith/complex_arith.h \
 test/../SLISC/arith/../dense/Svec.h test/../SLISC/arith/../dense/Scmat.h \
 test/../SLISC/arith/../dense/Scmat3.h \
 test/../SLISC/arith/../dense/Jcmat3.h test/../SLISC/util/random.h \
 test/../SLISC/util/../arith/arith2.h
	$(opt_compiler) $(flags) -c $<
