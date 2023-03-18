test_odeint.o: test/test_odeint.cpp test/../SLISC/sci/odeint.h \
 test/../SLISC/sci/../arith/copy.h \
 test/../SLISC/sci/../arith/../arith/compare.h \
 test/../SLISC/sci/../arith/../arith/../dense/Vec.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/../global.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/../config.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/../prec/quad_math_declare.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/../prec/quad_math.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/../arith/Imag.h \
 test/../SLISC/sci/../arith/../arith/../dense/../dense/../str/str.h \
 test/../SLISC/sci/../arith/../arith/../dense/Mat.h \
 test/../SLISC/sci/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/sci/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/sci/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/sci/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/sci/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../arith/scalar_arith.h \
 test/../SLISC/sci/../arith/../arith/../sparse/../arith/../arith/complex_arith.h \
 test/../SLISC/sci/../arith/../arith/../dense/Svec.h \
 test/../SLISC/sci/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/sci/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/sci/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/sci/../arith/../dense/cut.h test/../SLISC/file/file.h \
 test/../SLISC/file/../util/time.h test/../SLISC/file/../util/linux.h \
 test/../SLISC/file/../util/bit.h test/../SLISC/file/../arith/arith1.h \
 test/../SLISC/file/../str/unicode.h \
 test/../SLISC/file/../str/utfcpp/utf8.h \
 test/../SLISC/file/../str/utfcpp/utf8/checked.h \
 test/../SLISC/file/../str/utfcpp/utf8/core.h \
 test/../SLISC/file/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/file/../algo/sort.h \
 test/../SLISC/file/../algo/../algo/heap.h \
 test/../SLISC/file/../algo/../algo/../util/random.h \
 test/../SLISC/file/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/file/../algo/../arith/reorder.h
	$(opt_compiler) $(flags) -c $<
