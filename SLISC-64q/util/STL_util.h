// extension for standard library
#pragma once
#include "../global.h"

namespace slisc {

// use sort(iter1, iter2, cmp_inv()) for descending sort
struct cmp_inv {
	template <class T1, class T2>
	bool operator()(const T1 &s1, const T2 &s2) { return s2 < s1; }
};

// use sort(iter1, iter2, cmp_second()) to sort the second element of pair
struct cmp_second {
	template<class T11, class T12, class T21, class T22>
	bool operator()(const pair<T11,T12> &s1, const pair<T21,T22> &s2) { return s1.second < s2.second; }
};

// combine different hash
// from boost library
template<class T>
inline void hash_combine(size_t &hash, const T &v) {
	hash ^= std::hash<T>{}(v) + 0x9e3779b9 + (hash << 6) + (hash >> 2);
}

// similar to std::hash, for pair<T,T1> as key
struct hash_pair {
	template<class T, class T1>
	size_t operator()(const pair<T,T1> &a) const {
		size_t h = 0;
		hash_combine(h, a.first);
		hash_combine(h, a.second);
		return h;
	}
};

template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const pair<T1,T2> &s) {
	os << "(" << s.first << ", " << s.second << ")";
	return os;
}

template <class T, class H>
std::ostream &operator<<(std::ostream &os, const unordered_set<T, H> &v) {
	for (auto &e : v)
		cout << e << endl;
	return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const set<T> &v) {
	for (auto &e : v)
		cout << e << " ";
	return os;
}

template <class T1, class T2, class H>
std::ostream &operator<<(std::ostream &os, const unordered_map<T1, T2, H> &v) {
	for (auto &e : v)
		cout << e.first << " -> " << e.second << endl;
	return os;
}

template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const map<T1, T2> &v) {
	for (auto &e : v)
		cout << e << endl;
	return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const vector<T> &v) {
	for (Long i = 0; i < (Long)v.size(); ++i)
		cout << i << ":" << v[i] << " ";
	return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const vector<vector<T>> &v) {
	for (auto &row : v) {
		for (auto &e: row)
			cout << std::setw(3) << e << " ";
		cout << endl;
	}
	return os;
}

// priority queue smaller value first
template <class T>
using priority_queue2 = std::priority_queue<T, vector<T>, std::greater<T>>;

// find minimum `second` of unordered_map and others
template <class T>
typename T::const_iterator const min_second(const T &v)
{
	auto it = v.begin(), it0 = it;
	auto val = it->second;
	for (++it; it != v.end(); ++it) {
		if (it->second < val) {
			val = it->second; it0 = it;
		}
	}
	return it0;
}

template <class T>
typename T::const_iterator const max_second(const T &v)
{
	auto it = v.begin(), it0 = it;
	auto val = it->second;
	for (++it; it != v.end(); ++it) {
		if (val < it->second) {
			val = it->second; it0 = it;
		}
	}
	return it0;
}

// get n-th element from iterator
// for iterator supporting only ++
template<class T>
inline typename T::iterator iter_ind(T &s, Long_I ind)
{
	auto p = s.begin();
	for (Long i = 0; i < ind; ++i)
		++p;
	return p;
}

template<class T>
inline void erase(vector<T> &v, Long_I ind)
{
	v.erase(v.begin() + ind);
}

inline Str &operator<<(Str_IO s, char c) { return s += c; }

inline Str &operator<<(Str_IO s, const char *p) { return s += p; }

inline Str &operator<<(Str_IO s, Str_I str) { return s += str; }

} // namespace slisc
