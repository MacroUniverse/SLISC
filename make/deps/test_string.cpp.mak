test_string.o: test/test_string.cpp test/../SLISC/str/str.h \
 test/../SLISC/str/../global.h test/../SLISC/str/../config.h \
 test/../SLISC/str/../prec/quad_math_declare.h \
 test/../SLISC/str/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
