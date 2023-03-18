test_scalar_arith.o: test/test_scalar_arith.cpp \
 test/../SLISC/arith/scalar_arith.h \
 test/../SLISC/arith/../arith/complex_arith.h \
 test/../SLISC/arith/../arith/../global.h \
 test/../SLISC/arith/../arith/../config.h \
 test/../SLISC/arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/arith/../arith/../prec/quad_math.h \
 test/../SLISC/arith/../arith/Imag.h test/../SLISC/util/STL_util.h
	$(opt_compiler) $(flags) -c $<
