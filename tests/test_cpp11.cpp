// don't use SLISC
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>
#include <functional>
#include <unordered_set>
#include <unordered_map>

using namespace std;

bool compare2(int a, int b) { return a < b; }

// test range-based for loop
struct My_p
{
	vector<double> &m_v;
	int m_i;
	My_p(vector<double> &v, int ind): m_v(v), m_i(ind) {}
	double &operator*() {
		return m_v[m_i];
	}
	void operator++() {
		++m_i;
	}
	bool operator!=(My_p &p) {
		return m_i != p.m_i;
	}
};

// test range-based for loop
struct My_v
{
	vector<double> m_a;
	My_v(int N): m_a(N) {
		for (int i = 0; i < N; ++i)
			m_a[i] = i;
	}
	My_p begin() { return My_p(m_a, 0); }
	My_p end() { return My_p(m_a, m_a.size()); }
};

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

	// unordered set
	unordered_set<int> set;
	set.insert(3); set.insert(1); set.insert(2);
	if (set.size() != 3) throw "failed!";
	// for (auto e : set)
	//	cout << e << endl;
	// set.max_size() == 2^60-1
	if (*set.find(1) != 1) throw "failed!";
	if (set.find(123) != set.end()) throw "failed!";

	string s = "123234345";
	if (s.find('a') != SIZE_MAX) throw "failed!";

	// map
	unordered_map<char, int> mp;
	// can assume all entries already exist
	mp['a'] = 2; mp['b'] = 3; mp['c'] = 4;
	++mp['a']; --mp['b']; mp.erase('c');
	// for (pair<const char, int> &p : mp)
		// cout << p.first << " -> " << p.second << endl;

	// range-based for loop
	double a[] = {0,1,2,3,4};
	My_v v(5); int i = 0;
	for (auto &e : v) {
		if (e != a[i]) throw "failed!";
		++i;
	}

	// move(), swap()
	vector<int> aa = {1,2,3}, bb;
	bb = move(aa);
	swap(aa, bb);
}

#ifndef SLS_TEST_ALL
int main() { test_cpp11(); }
#endif
