test_string.o: tests/test_string.cpp tests/../SLISC/str/str.h \
 tests/../SLISC/str/../global.h tests/../SLISC/str/../config.h \
 tests/../SLISC/str/../prec/quad_math_declare.h \
 tests/../SLISC/str/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_string.cpp
