#pragma once
#include "global.h"

namespace slisc {
	// insert into a sorted dequeue
	template <class T>
	inline void sorted_insert(deque<T> &q, const T &elm)
	{
		if (q.empty()) {
			q.push_back(elm); return;
		}
		if (elm >= q.back()) {
			q.insert(q.end(), elm); return;
		}
		for (auto iter = q.begin(); ; ++iter) {
			if (elm <= *iter) {
				q.insert(iter, elm); return;
			}
		}
	}

	// insert into a sorted dequeue (sorted by val[elm])
	template <class T, class T1>
	inline void sorted_insert(deque<T> &q, const T1 &vals, const T &elm)
	{
		if (q.empty()) {
			q.push_back(elm); return;
		}
		T val = vals[elm];
		if (val >= vals[q.back()]) {
			q.insert(q.end(), elm); return;
		}
		for (auto iter = q.begin(); ; ++iter) {
			if (val <= vals[*iter]) {
				q.insert(iter, elm); return;
			}
		}
	}
} // namespace slisc
