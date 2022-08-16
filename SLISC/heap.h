#pragma once

namespace slisc {

	// To heapify a subtree rooted with `node`
	// the tree must be a max tree except for `node`
	// `heapify` will make the tree a max tree
	// left = 2*node + 1, right = 2*node + 2;
	template <class T>
	void heapify(T *v, Long N, Long node)
	{
		// Find largest among root (node), left child and right child
		Long imax = node, left = 2*node + 1, right = 2*node + 2;
		if (left < N && v[left] > v[imax])
			imax = left;
		if (right < N && v[right] > v[imax])
			imax = right;
		if (imax != node) {
			swap(v[node], v[imax]);
			heapify(v, N, imax);
		}
	}

} // namespace slisc
