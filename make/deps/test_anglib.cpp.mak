test_anglib.o: test/test_anglib.cpp test/../SLISC/spec/anglib.h \
 test/../SLISC/spec/../arith/scalar_arith.h \
 test/../SLISC/spec/../arith/../arith/complex_arith.h \
 test/../SLISC/spec/../arith/../arith/../global.h \
 test/../SLISC/spec/../arith/../arith/../config.h \
 test/../SLISC/spec/../arith/../arith/../prec/quad_math_declare.h \
 test/../SLISC/spec/../arith/../arith/../prec/quad_math.h \
 test/../SLISC/spec/../arith/../arith/Imag.h
	$(opt_compiler) $(flags) -c $<
