#include "../SLISC/sym/sym_tree.h"

void test_sym()
{
	sym_pool pool;
	
	auto expr = pool.add.get();
	expr.arg = pool.int.get();
	expr.arg.next = pool.int.get();
	expr.print();
}

#ifndef SLS_TEST_ALL
int main() { test_sym(); }
#endif
