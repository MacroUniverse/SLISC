// extension for standard library
#pragma once
#include "global.h"

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

template<class T1, class T2>
std::ostream &operator<<(std::ostream &os, const pair<T1,T2> &s) {
	os << "(" << s.first << ", " << s.second << ")";
	return os;
}

} // namespace slisc
