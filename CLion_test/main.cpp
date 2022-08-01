#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

template<class T> // from boost library
inline void hash_combine(size_t &seed, const T &v) {
    seed ^= hash<T>{}(v) + 0x9e3779b9 + (seed << 6) + (seed >> 2);
}

struct hash_pair { // similar to std::hash, for pair<>
    template<class T, class T1>
    size_t operator()(const pair<T,T1> &a) const {
        size_t h = 0;
        hash_combine(h, a.first);
        hash_combine(h, a.second);
        return h;
    }
};

int main() {
    vector<int> v;
    int imax = numeric_limits<int>::max();
    while (1) {
        int tmp = imax;
        cin >> tmp;
        if (tmp == imax) break;
        v.push_back(tmp);
        cin.ignore(imax, '\n');
    }
    return 0;
}
