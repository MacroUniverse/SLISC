#pragma once
#include "global.h"

namespace slisc {

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

} // namespace slisc
