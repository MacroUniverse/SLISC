test_eigen.o: test/test_eigen.cpp make/deps/test_eigen.cpp.mak
	$(opt_compiler) $(flags) -c test/test_eigen.cpp
