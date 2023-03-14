#pragma once
#include "../util/random.h"

namespace slisc {
    // To heapify a subtree rooted with `node`
    // the tree must be a max tree except for `node`
    // `heapify` will make the tree a max tree
    // left = 2*node + 1, right = 2*node + 2;
    template <class T>
    inline void heapify(T *v, Long N, Long node)
    {
        // Find largest among root (node), left child and right child
        Long imax = node, left = 2*node + 1, right = left + 1;
        if (left < N && v[left] > v[imax])
            imax = left;
        if (right < N && v[right] > v[imax])
            imax = right;
        if (imax != node) {
            swap(v[node], v[imax]);
            heapify(v, N, imax);
        }
    }

    // reverse heapify (only the last element might not be sorted)
    template <class T>
    inline void heapify2(T *v, Long N)
    {
        Long node = N-1;
        while (node != 0) {
            Long child = node;
            node = (node - 1) / 2;
            if (v[child] < v[node])
                swap(v[node], v[child]);
            else
                break;
        }
    }

    // print the binary tree
    // it does reverse inorder traversal
    template <class T>
    inline void heap_print(const T *v, Long_I N, int space = 0, int ind = 0)
    {
        const int COUNT = 7;
        if (ind >= N) return;
        space += COUNT;
        // Process right child first
        heap_print(v, N, space, 2*ind+2);
        // Print current node after space
        cout << string(space-COUNT, ' ');
        cout << v[ind] << endl;
        // Process left child
        heap_print(v, N, space, 2*ind+1);
    }

    // check if is a big heap
    template <class T>
    inline bool heap_check(T *v, Long N, Long node = 0)
    {
        Long left = 2*node + 1;
        if (left >= N) return true;
        if (v[left] < v[node]) return false;
        if (!heap_check(v, N, left))
            return false;
        Long right = left + 1;
        if (right >= N) return true;
        if (v[right] < v[node]) return false;
        return heap_check(v, N, left);
    }

    // make a min heap
    template <class T>
    inline void heap_make(T *v, Long_I N)
    {
        for (Long i = N / 2 - 1; i >= 0; i--)
            heapify(v, N, i);
    }

    // pop from a heap then heapify
    // resulting heap will have N-1 elm
    template <class T>
    inline T heap_pop(T *v, Long_I N)
    {
        T ret = v[0]; v[0] = v[N-1];
        heapify(v, N-1, 0);
        return ret;
    }

    // Main function to do heap sort
    template <class T>
    inline void heapsort(T *v, Long N)
    {
        heap_make(v, N);
        for (Long i = N - 1; i >= 0; i--)
            v[i] = heap_pop(v, i+1);
    }
} // namespace slisc
