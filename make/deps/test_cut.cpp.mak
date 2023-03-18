test_cut.o: test/test_cut.cpp test/../SLISC/dense/cut.h \
 test/../SLISC/dense/../dense/Vec.h \
 test/../SLISC/dense/../dense/../dense/Vbase.h \
 test/../SLISC/dense/../dense/../dense/../global.h \
 test/../SLISC/dense/../dense/../dense/../config.h \
 test/../SLISC/dense/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/dense/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/dense/../dense/../dense/../arith/Imag.h \
 test/../SLISC/dense/../dense/../dense/../str/str.h \
 test/../SLISC/dense/../dense/Mat.h test/../SLISC/dense/../dense/Cmat.h \
 test/../SLISC/dense/../dense/Cmat3.h \
 test/../SLISC/dense/../dense/Cmat4.h test/../SLISC/dense/../dense/Svec.h \
 test/../SLISC/dense/../dense/Dvec.h test/../SLISC/dense/../dense/Scmat.h \
 test/../SLISC/dense/../dense/Scmat3.h \
 test/../SLISC/dense/../dense/Dcmat.h \
 test/../SLISC/dense/../dense/Jcmat3.h test/../SLISC/arith/arith2.h \
 test/../SLISC/arith/../arith/scalar_arith.h \
 test/../SLISC/arith/../arith/../arith/complex_arith.h \
 test/../SLISC/arith/../arith/compare.h \
 test/../SLISC/arith/../arith/../dense/Mat3.h \
 test/../SLISC/arith/../arith/../sparse/Cband.h \
 test/../SLISC/arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/arith/../arith/../sparse/Cmobd.h
	$(opt_compiler) $(flags) -c $<
