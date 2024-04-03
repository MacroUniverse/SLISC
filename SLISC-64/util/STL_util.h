// extension for standard library
#pragma once
#include "../global.h"

namespace slisc {

// combine 2 size_t hashs
inline size_t hash_combine(size_t hash1, size_t hash2) {
	hash1 ^= hash2 + 0x9e3779b9 + (hash1 << 6) + (hash1 >> 2);
	return hash1;
}

// hash tuple<>
// if you think variadic template is too tricky, use this instead
// template <class T1, class T2, class T3>
// struct hash<tuple<T1,T2,T3>> {
//     size_t operator()(const tuple<T1,T2,T3>& v) const {
// 		return slisc::hash_combine(
// 			hash<T1>{}(get<0>(v)),
// 			hash<T2>{}(get<1>(v)),
// 			hash<T3>{}(get<3>(v))
// 		);
//     }
// };
template<int Idx, typename... Args>
struct hash_tuple_impl {
	void operator()(const tuple<Args...> &tup, size_t &hash) const
	{
		hash_tuple_impl<Idx-1, Args...>{}(tup, hash);
		auto &val = get<Idx>(tup);
		// get element type, `decay` is to remove the `const &` from `decltype(get<1>(tup)`
		using Telem = typename std::decay<decltype(val)>::type;
		hash = hash_combine(hash, std::hash<Telem>{}(val));
	}
};

// has to use struct instead of function template because function template doesn't allow partial specialization
template<typename... Args>
struct hash_tuple_impl<-1, Args...> {
	void operator()(const tuple<Args...> &tup, size_t &hash) const {}
};

} // namespace slisc

namespace std {
// hash a vector
template <class T>
struct hash<vector<T>> {
    size_t operator()(const vector<T>& v) const {
        size_t h = 0;
		auto hasher = hash<T>{};
        for(const T& s : v)
            h = slisc::hash_combine(h, hasher(s));
        return h;
    }
};

// hash a pair
template <class T, class T1>
struct hash<pair<T,T1>> {
	size_t operator()(const pair<T,T1> &a) const {
		return slisc::hash_combine(hash<T>{}(a.first),
			hash<T1>{}(a.second));
	}
};

// hash a tuple
template<typename... Args>
struct hash<tuple<Args...>> {
	size_t operator()(const tuple<Args...> &tup) const
	{
		size_t hash = 0;
		constexpr int N = (int)tuple_size<tuple<Args...>>::value;
		slisc::hash_tuple_impl<N-1, Args...>{}(tup, hash);
		return hash;
	}
};

} // namespace std

namespace slisc {

// ====== comparer ========

// use sort(iter1, iter2, cmp_inv()) for descending sort
struct cmp_inv {
	template <class T1, class T2>
	bool operator()(const T1 &s1, const T2 &s2) const { return s2 > s1; }
};

// use sort(iter1, iter2, cmp_second()) to sort the second element of pair
struct cmp_second {
	template<class T11, class T12, class T21, class T22>
	bool operator()(const pair<T11,T12> &s1, const pair<T21,T22> &s2) const { return s1.second < s2.second; }
};

struct cmp_second_inv {
	template<class T11, class T12, class T21, class T22>
	bool operator()(const pair<T11,T12> &s1, const pair<T21,T22> &s2) const { return s1.second > s2.second; }
};

// ====== iterator hack ======

// erase ind-th element from vector
template<class T>
inline void erase(vector<T> &v, Long_I ind)
{
	v.erase(v.begin() + ind);
}

// get n-th element from iterator supporting only ++
template<class T>
inline typename T::iterator iter_ind(T &s, Long_I ind)
{
	auto p = s.begin();
	for (Long i = 0; i < ind; ++i)
		++p;
	return p;
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

// ====== print STL containers ==========
template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const pair<T1,T2> &s) {
	os << "(" << s.first << ", " << s.second << ")";
	return os;
}

template <class T, class H>
std::ostream &operator<<(std::ostream &os, const unordered_set<T, H> &v) {
	cout << "(size " << v.size() << ") {";
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (it != v.begin())
			cout << ", ";
		cout << *it;
	}
	cout << '}' << endl;
	return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const set<T> &v) {
	cout << "(size " << v.size() << ") {";
	for (auto it = v.begin(); it != v.end(); ++it) {
		if (it != v.begin())
			cout << ", ";
		cout << *it;
	}
	cout << '}' << endl;
	return os;
}

template <class T1, class T2, class H>
std::ostream &operator<<(std::ostream &os, const unordered_map<T1, T2, H> &v) {
	cout << "(size " << v.size() << ") {";
	for (auto &e : v)
		cout << e.first << ": " << e.second << '\n';
	cout << '}' << endl;
	return os;
}

template <class T1, class T2>
std::ostream &operator<<(std::ostream &os, const map<T1, T2> &v) {
	cout << "(size " << v.size() << ") {\n";
	for (auto &e : v)
		cout << e.first << ": " << e.second << '\n';
	cout << '}' << endl;
	return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const vector<T> &v) {
	cout << "(size " << v.size() << ") (";
	for (Long i = 0; i < (Long)v.size(); ++i)
		cout << i << ":" << v[i] << " ";
	cout << ')' << endl;
	return os;
}

template <class T>
std::ostream &operator<<(std::ostream &os, const vector<vector<T>> &v) {
	cout << "(size " << v.size() << ") (";
	for (auto &row : v) {
		for (auto &e: row)
			cout << std::setw(3) << e << " ";
		cout << endl;
	}
	cout << ')' << endl;
	return os;
}

// ======= string as stream ==========
inline Str &operator<<(Str_IO s, char c) { return s += c; }

inline Str &operator<<(Str_IO s, const char *p) { return s += p; }

inline Str &operator<<(Str_IO s, Str_I str) { return s += str; }

inline Str &operator<<(Str_IO s, Int_I n) { return s += to_string(n); }

inline Str &operator<<(Str_IO s, Llong_I n) { return s += to_string(n); }

inline Str &clear(Str &s) { s.clear(); return s; }

template <class T>
inline Str &operator<<(Str_IO s, const T &val) { return s += to_string(val); }

} // namespace slisc
