test_matb.o: test/test_matb.cpp test/../SLISC/arith/arith4.h \
 test/../SLISC/arith/../arith/scalar_arith.h \
 test/../SLISC/arith/../arith/../arith/complex_arith.h \
 test/../SLISC/arith/../arith/../arith/../global.h \
 test/../SLISC/arith/../arith/../arith/../config.h \
 test/../SLISC/arith/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/arith/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/arith/../arith/../arith/Imag.h \
 test/../SLISC/arith/../arith/compare.h \
 test/../SLISC/arith/../arith/../dense/Vec.h \
 test/../SLISC/arith/../arith/../dense/../dense/Vbase.h \
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
 test/../SLISC/arith/../arith/../dense/Svec.h \
 test/../SLISC/arith/../arith/../dense/Scmat.h \
 test/../SLISC/arith/../arith/../dense/Scmat3.h \
 test/../SLISC/arith/../arith/../dense/Jcmat3.h test/../SLISC/file/matb.h \
 test/../SLISC/file/../file/matt.h \
 test/../SLISC/file/../file/../file/file.h \
 test/../SLISC/file/../file/../file/../util/time.h \
 test/../SLISC/file/../file/../file/../util/linux.h \
 test/../SLISC/file/../file/../file/../util/bit.h \
 test/../SLISC/file/../file/../file/../arith/arith1.h \
 test/../SLISC/file/../file/../file/../str/unicode.h \
 test/../SLISC/file/../file/../file/../str/utfcpp/utf8.h \
 test/../SLISC/file/../file/../file/../str/utfcpp/utf8/checked.h \
 test/../SLISC/file/../file/../file/../str/utfcpp/utf8/core.h \
 test/../SLISC/file/../file/../file/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/file/../file/../file/../algo/sort.h \
 test/../SLISC/file/../file/../file/../algo/../algo/heap.h \
 test/../SLISC/file/../file/../file/../algo/../algo/../util/random.h \
 test/../SLISC/file/../file/../file/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/file/../file/../file/../algo/../arith/reorder.h \
 test/../SLISC/file/../file/../file/../algo/../arith/../arith/copy.h \
 test/../SLISC/file/../file/../file/../algo/../arith/../arith/../dense/cut.h \
 test/../SLISC/util/sha1sum.h
	$(opt_compiler) $(flags) -c $<
