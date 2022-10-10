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

// #include <iostream>
// #include <climits>
// #include <float.h>
// using namespace std;

// int main()
// {
// 	//======================= no abort
// 	cout << "0" << endl;
// 	{char a = 120, b = 120;
// 	char c = a + b;
// 	cout << (int)c << endl;}

// 	cout << "0.5" << endl;
// 	{unsigned short a = USHRT_MAX/3*2, b = USHRT_MAX/3*2;
// 	unsigned short c = a + b;
// 	cout << c << endl;}

// 	cout << "1" << endl;
// 	{short a = SHRT_MAX/3*2, b = SHRT_MAX/3*2;
// 	short c = a + b;
// 	cout << c << endl;}

// 	cout << "5" << endl;
// 	{unsigned int a = UINT_MAX/3*2, b = UINT_MAX/3*2;
// 	unsigned int c = a + b;
// 	cout << c << endl;}

// 	cout << "6" << endl;
// 	{unsigned long long a = UINT_MAX/3*2, b = UINT_MAX/3*2;
// 	unsigned long long c = a + b;
// 	cout << c << endl;}

// 	cout << "7" << endl;
// 	{double a = DBL_MAX/3*2, b = DBL_MAX/3*2;
// 	double c = a + b;
// 	cout << c << endl;} // inf

// 	//============================= will abort with -ftrapv flag

// 	// cout << "4" << endl;
// 	// {long long a = LLONG_MAX/3*2, b = LLONG_MAX/3*2;
// 	// long long c = a + b;
// 	// cout << c << endl;}

// 	// cout << "3" << endl;
// 	// {long a = LONG_MAX/3*2, b = LONG_MAX/3*2;
// 	// long c = a + b;
// 	// cout << c << endl;}

// 	// cout << "2" << endl;
// 	// {int a = INT_MAX/3*2, b = INT_MAX/3*2;
// 	// int c = a + b;
// 	// cout << c << endl;}

// 	// =========  see also SafeInt library and similar ==============
// }
