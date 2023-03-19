test_interp1.o: test/test_interp1.cpp make/deps/test_interp1.cpp.mak \
 test/../SLISC/sci/interp1.h test/../SLISC/sci/../dense/Vec.h \
 test/../SLISC/sci/../dense/../dense/Vbase.h \
 test/../SLISC/sci/../dense/../dense/../global.h \
 test/../SLISC/sci/../dense/../dense/../config.h \
 test/../SLISC/sci/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/sci/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/sci/../dense/../dense/../arith/Imag.h \
 test/../SLISC/sci/../dense/../dense/../str/str.h \
 test/../SLISC/sci/../dense/Svec.h test/../SLISC/sci/../dense/Dvec.h \
 test/../SLISC/sci/../arith/arith1.h \
 test/../SLISC/sci/../arith/../arith/scalar_arith.h \
 test/../SLISC/sci/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/sci/../arith/../arith/compare.h \
 test/../SLISC/sci/../arith/../arith/../dense/Mat.h \
 test/../SLISC/sci/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/sci/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/sci/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/sci/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/sci/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/sci/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/sci/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/arith/arith2.h test/../SLISC/arith/arith4.h
	$(opt_compiler) $(flags) -c test/test_interp1.cpp
