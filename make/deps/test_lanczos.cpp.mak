test_lanczos.o: test/test_lanczos.cpp test/../SLISC/tdse/lanczos.h \
 test/../SLISC/tdse/../global.h test/../SLISC/tdse/../config.h \
 test/../SLISC/tdse/../prec/quad_math_declare.h \
 test/../SLISC/tdse/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
