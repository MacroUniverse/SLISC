#include "../SLISC/SafeInt.h"
#include <iostream>
#include <climits>
#include <unordered_map>

void test_SafeInt()
{
	using namespace std;
	SafeInt<unsigned int> a = 1, b = 2, c;
	c = a * b;
	// unordered_map<SafeInt<char>, SafeInt<char>> umap;
	// umap[a] = b; umap[b] = c; umap[c] = a;
	// cout << (unsigned int)c << endl;
}
