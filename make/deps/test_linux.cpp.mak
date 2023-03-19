test_linux.o: tests/test_linux.cpp tests/../SLISC/util/linux.h \
 tests/../SLISC/util/../global.h tests/../SLISC/util/../config.h \
 tests/../SLISC/util/../prec/quad_math_declare.h \
 tests/../SLISC/util/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_linux.cpp
