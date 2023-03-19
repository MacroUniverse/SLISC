test_arpack.o: test/test_arpack.cpp make/deps/test_arpack.cpp.mak
	$(opt_compiler) $(flags) -c test/test_arpack.cpp
