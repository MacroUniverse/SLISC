test_time.o: tests/test_time.cpp tests/../SLISC/util/time.h \
 tests/../SLISC/util/../str/str.h tests/../SLISC/util/../str/../global.h \
 tests/../SLISC/util/../str/../config.h \
 tests/../SLISC/util/../str/../prec/quad_math_declare.h \
 tests/../SLISC/util/../str/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_time.cpp
