test_hungarian.o: test/test_hungarian.cpp \
 make/deps/test_hungarian.cpp.mak test/../SLISC/algo/hungarian.h \
 test/../SLISC/algo/../arith/copy.h \
 test/../SLISC/algo/../arith/../arith/compare.h \
 test/../SLISC/algo/../arith/../arith/../dense/Vec.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/../global.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/../config.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/../arith/Imag.h \
 test/../SLISC/algo/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/algo/../arith/../arith/../dense/Mat.h \
 test/../SLISC/algo/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/algo/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/algo/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/algo/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/algo/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/algo/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/algo/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/algo/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/algo/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/algo/../arith/../arith/../sparse/../arith/scalar_arith.h \
 test/../SLISC/algo/../arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 test/../SLISC/algo/../arith/../arith/../dense/Svec.h \
 test/../SLISC/algo/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/algo/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/algo/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/algo/../arith/../dense/cut.h \
 test/../SLISC/algo/../arith/arith1.h \
 test/../SLISC/algo/../arith/arith4.h
	$(opt_compiler) $(flags) -c test/test_hungarian.cpp
