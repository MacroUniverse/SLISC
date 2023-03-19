test_linbcg.o: test/test_linbcg.cpp make/deps/test_linbcg.cpp.mak \
 test/../SLISC/lin/linbcg.h test/../SLISC/lin/../arith/arith1.h \
 test/../SLISC/lin/../arith/../arith/scalar_arith.h \
 test/../SLISC/lin/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/lin/../arith/../arith/../arith/../global.h \
 test/../SLISC/lin/../arith/../arith/../arith/../config.h \
 test/../SLISC/lin/../arith/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/lin/../arith/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/lin/../arith/../arith/../arith/Imag.h \
 test/../SLISC/lin/../arith/../arith/compare.h \
 test/../SLISC/lin/../arith/../arith/../dense/Vec.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/lin/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/lin/../arith/../arith/../dense/Mat.h \
 test/../SLISC/lin/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/lin/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/lin/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/lin/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/lin/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/lin/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/lin/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/lin/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/lin/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/lin/../arith/../arith/../dense/Svec.h \
 test/../SLISC/lin/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/lin/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/lin/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/lin/../arith/arith2.h test/../SLISC/lin/../arith/arith4.h \
 test/../SLISC/lin/../dense/cut.h test/../SLISC/lin/../lin/mul.h \
 test/../SLISC/lin/../lin/../arith/copy.h test/../SLISC/arith/reorder.h
	$(opt_compiler) $(flags) -c test/test_linbcg.cpp
