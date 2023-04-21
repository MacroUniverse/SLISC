test_matt.o: tests/test_matt.cpp tests/../SLISC/arith/arith4.h \
 tests/../SLISC/arith/../arith/scalar_arith.h \
 tests/../SLISC/arith/../arith/../arith/complex_arith.h \
 tests/../SLISC/arith/../arith/../arith/../global.h \
 tests/../SLISC/arith/../arith/../arith/../config.h \
 tests/../SLISC/arith/../arith/../arith/../prec/quad_math_declare.h \
 tests/../SLISC/arith/../arith/../arith/../prec/quad_math.h \
 tests/../SLISC/arith/../arith/../arith/Imag.h \
 tests/../SLISC/arith/../arith/compare.h \
 tests/../SLISC/arith/../arith/../dense/Vec.h \
 tests/../SLISC/arith/../arith/../dense/../dense/Vbase.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/str.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/unicode.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/core.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/cpp17.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/checked.h \
 tests/../SLISC/arith/../arith/../dense/../dense/../str/../str/utfcpp/utf8/unchecked.h \
 tests/../SLISC/arith/../arith/../dense/Mat.h \
 tests/../SLISC/arith/../arith/../dense/Mat3.h \
 tests/../SLISC/arith/../arith/../dense/Cmat.h \
 tests/../SLISC/arith/../arith/../dense/Cmat3.h \
 tests/../SLISC/arith/../arith/../dense/Cmat4.h \
 tests/../SLISC/arith/../arith/../sparse/Cband.h \
 tests/../SLISC/arith/../arith/../sparse/../dense/Dvec.h \
 tests/../SLISC/arith/../arith/../sparse/../dense/Dcmat.h \
 tests/../SLISC/arith/../arith/../sparse/Mcoo.h \
 tests/../SLISC/arith/../arith/../sparse/Cmobd.h \
 tests/../SLISC/arith/../arith/../dense/Svec.h \
 tests/../SLISC/arith/../arith/../dense/Scmat.h \
 tests/../SLISC/arith/../arith/../dense/Scmat3.h \
 tests/../SLISC/arith/../arith/../dense/Jcmat3.h \
 tests/../SLISC/file/matt.h tests/../SLISC/file/../file/file.h \
 tests/../SLISC/file/../file/../util/time.h \
 tests/../SLISC/file/../file/../util/linux.h \
 tests/../SLISC/file/../file/../util/bit.h \
 tests/../SLISC/file/../file/../arith/arith1.h \
 tests/../SLISC/file/../file/../algo/sort.h \
 tests/../SLISC/file/../file/../algo/../algo/heap.h \
 tests/../SLISC/file/../file/../algo/../algo/../util/random.h \
 tests/../SLISC/file/../file/../algo/../algo/../util/../arith/arith2.h \
 tests/../SLISC/file/../file/../algo/../algo/../util/../util/STL_util.h \
 tests/../SLISC/file/../file/../algo/../arith/reorder.h \
 tests/../SLISC/file/../file/../algo/../arith/../arith/copy.h \
 tests/../SLISC/file/../file/../algo/../arith/../arith/../dense/cut.h \
 tests/../SLISC/str/disp.h
	$(opt_compiler) $(flags) -c tests/test_matt.cpp
