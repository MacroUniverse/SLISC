test_fft.o: test/test_fft.cpp test/../SLISC/sci/fft.h \
 test/../SLISC/sci/../dense/cut.h \
 test/../SLISC/sci/../dense/../dense/Vec.h \
 test/../SLISC/sci/../dense/../dense/../dense/Vbase.h \
 test/../SLISC/sci/../dense/../dense/../dense/../global.h \
 test/../SLISC/sci/../dense/../dense/../dense/../config.h \
 test/../SLISC/sci/../dense/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/sci/../dense/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/sci/../dense/../dense/../dense/../arith/Imag.h \
 test/../SLISC/sci/../dense/../dense/../dense/../str/str.h \
 test/../SLISC/sci/../dense/../dense/Mat.h \
 test/../SLISC/sci/../dense/../dense/Cmat.h \
 test/../SLISC/sci/../dense/../dense/Cmat3.h \
 test/../SLISC/sci/../dense/../dense/Cmat4.h \
 test/../SLISC/sci/../dense/../dense/Svec.h \
 test/../SLISC/sci/../dense/../dense/Dvec.h \
 test/../SLISC/sci/../dense/../dense/Scmat.h \
 test/../SLISC/sci/../dense/../dense/Scmat3.h \
 test/../SLISC/sci/../dense/../dense/Dcmat.h \
 test/../SLISC/sci/../dense/../dense/Jcmat3.h \
 test/../SLISC/sci/../arith/copy.h \
 test/../SLISC/sci/../arith/../arith/compare.h \
 test/../SLISC/sci/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../arith/scalar_arith.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 test/../SLISC/arith/arith1.h test/../SLISC/arith/arith2.h \
 test/../SLISC/arith/arith4.h
	$(opt_compiler) $(flags) -c $<
