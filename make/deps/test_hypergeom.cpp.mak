test_hypergeom.o: test/test_hypergeom.cpp \
 make/deps/test_hypergeom.cpp.mak test/../SLISC/spec/hypergeom.h \
 test/../SLISC/spec/../str/str.h test/../SLISC/spec/../str/../global.h \
 test/../SLISC/spec/../str/../config.h \
 test/../SLISC/spec/../str/../prec/quad_math_declare.h \
 test/../SLISC/spec/../str/../prec/quad_math.h
	$(opt_compiler) $(flags) -c test/test_hypergeom.cpp
