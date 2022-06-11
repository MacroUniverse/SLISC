#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <string>
#include <functional>

using namespace std;

bool compare2(int a, int b) { return a < b; }

void test_cpp11()
{
	// sort(), pair<>, and lambda expr, function<>, function to pointer
	vector<int> v1 = {1,3,2,4,5}, v2 = {1,2,3,4,5}, v3;
	int N = v1.size(); v3.resize(N);
	vector<pair<int, int>> p(N);
	for (int i = 0; i < N; ++i) {
		p[i].first = v1[i];
		p[i].second = i;
	}
	auto compare = [](const pair<int,int> &x, const pair<int,int> &y) { return x.first < y.first; };
	function<bool(const pair<int,int> &, const pair<int,int> &)> fun = compare;
	sort(p.begin(), p.end(), compare);
	sort(p.begin(), p.end(), fun);
	sort(p.begin(), p.end());
	for (int i = 0; i < N; ++i)
		if (p[i].first != i+1)
			throw "failed!";
	if ((&compare2)(2, 1) != 0)
		throw "failed!";
	bool (*func)(int, int) = &compare2;
	if (func(2, 1) != 0)
		throw "failed!";
	typedef bool (*T)(int, int);
	T func2 = &compare2;
	if (func2(2, 1) != 0)
		throw "failed!";
}
