test_hypergeom.o: tests/test_hypergeom.cpp \
 tests/../SLISC/spec/hypergeom.h tests/../SLISC/spec/../str/str.h \
 tests/../SLISC/spec/../str/../global.h \
 tests/../SLISC/spec/../str/../config.h \
 tests/../SLISC/spec/../str/../prec/quad_math_declare.h \
 tests/../SLISC/spec/../str/../prec/quad_math.h
	$(opt_compiler) $(flags) -c tests/test_hypergeom.cpp
