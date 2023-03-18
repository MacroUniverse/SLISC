test_arpack.o: test/test_arpack.cpp
	$(opt_compiler) $(flags) -c $<
