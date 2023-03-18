test_sha1sum.o: test/test_sha1sum.cpp test/../SLISC/util/sha1sum.h \
 test/../SLISC/util/../file/file.h test/../SLISC/util/../file/../global.h \
 test/../SLISC/util/../file/../config.h \
 test/../SLISC/util/../file/../prec/quad_math_declare.h \
 test/../SLISC/util/../file/../prec/quad_math.h \
 test/../SLISC/util/../file/../util/time.h \
 test/../SLISC/util/../file/../util/../str/str.h \
 test/../SLISC/util/../file/../util/linux.h \
 test/../SLISC/util/../file/../util/bit.h \
 test/../SLISC/util/../file/../arith/arith1.h \
 test/../SLISC/util/../file/../arith/../arith/scalar_arith.h \
 test/../SLISC/util/../file/../arith/../arith/../arith/complex_arith.h \
 test/../SLISC/util/../file/../arith/../arith/../arith/Imag.h \
 test/../SLISC/util/../file/../arith/../arith/compare.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Vec.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/../dense/Vbase.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Mat.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Mat3.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Cmat.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Cmat3.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Cmat4.h \
 test/../SLISC/util/../file/../arith/../arith/../sparse/Cband.h \
 test/../SLISC/util/../file/../arith/../arith/../sparse/../dense/Dvec.h \
 test/../SLISC/util/../file/../arith/../arith/../sparse/../dense/Dcmat.h \
 test/../SLISC/util/../file/../arith/../arith/../sparse/Mcoo.h \
 test/../SLISC/util/../file/../arith/../arith/../sparse/Cmobd.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Svec.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Scmat.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Scmat3.h \
 test/../SLISC/util/../file/../arith/../arith/../dense/Jcmat3.h \
 test/../SLISC/util/../file/../str/unicode.h \
 test/../SLISC/util/../file/../str/utfcpp/utf8.h \
 test/../SLISC/util/../file/../str/utfcpp/utf8/checked.h \
 test/../SLISC/util/../file/../str/utfcpp/utf8/core.h \
 test/../SLISC/util/../file/../str/utfcpp/utf8/unchecked.h \
 test/../SLISC/util/../file/../algo/sort.h \
 test/../SLISC/util/../file/../algo/../algo/heap.h \
 test/../SLISC/util/../file/../algo/../algo/../util/random.h \
 test/../SLISC/util/../file/../algo/../algo/../util/../arith/arith2.h \
 test/../SLISC/util/../file/../algo/../arith/reorder.h \
 test/../SLISC/util/../file/../algo/../arith/../arith/copy.h \
 test/../SLISC/util/../file/../algo/../arith/../arith/../dense/cut.h
	$(opt_compiler) $(flags) -c $<
