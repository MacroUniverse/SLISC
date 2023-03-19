test_legendreP.o: test/test_legendreP.cpp \
 make/deps/test_legendreP.cpp.mak test/../SLISC/spec/legendreP.h \
 test/../SLISC/spec/../arith/scalar_arith.h \
 test/../SLISC/spec/../arith/../arith/complex_arith.h \
 test/../SLISC/spec/../arith/../arith/../global.h \
 test/../SLISC/spec/../arith/../arith/../config.h \
 test/../SLISC/spec/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/spec/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/spec/../arith/../arith/Imag.h
	$(opt_compiler) $(flags) -c test/test_legendreP.cpp
