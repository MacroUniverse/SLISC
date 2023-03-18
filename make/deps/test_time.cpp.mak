test_time.o: test/test_time.cpp test/../SLISC/util/time.h \
 test/../SLISC/util/../str/str.h test/../SLISC/util/../str/../global.h \
 test/../SLISC/util/../str/../config.h \
 test/../SLISC/util/../str/../prec/quad_math_declare.h \
 test/../SLISC/util/../str/../prec/quad_math.h
	$(opt_compiler) $(flags) -c $<
