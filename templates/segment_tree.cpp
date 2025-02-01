#include <bits/stdc++.h>
using namespace std;

// Segment Tree without lazy tag
template <typename T>
class SegmentTree {
public:
    size_t size;
    vector<T> tree;
    const T DEFAULT = T{};

    SegmentTree(size_t n) {
        size = 1;
        while (size < n) size *= 2; // perfect binary tree
        tree.resize(2 * size - 1, DEFAULT);
    }

    T merge(T a, T b) { return a + b; }

    // build segment tree from source array
    void build(vector<T> &src, size_t idx, size_t left_close, size_t right_open) {
        // top down
        if (right_open - left_close == 1) {
            if (left < src.size()) tree[idx] = src[left_close];
            return;
        }

        size_t mid = left_close + (right_open - left_close) / 2;
        build(src, 2 * idx + 1, left_close, mid);
        build(src, 2 * idx + 2, mid, right_open);
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void build(vector<T> &src) { build(src, 0, 0, size); }

    // set value at index
    void set(size_t i_src, T val, size_t idx, size_t left_close, size_t right_open) {
        if (right_open - left_close == 1) {
            tree[idx] = val;
            return;
        }

        size_t mid = left_close + (right_open - left_close) / 2;
        if (i_src < mid) set(i_src, val, 2 * idx + 1, left_close, mid);
        else set(i_src, val, 2 * idx + 2, mid, right_open);
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void set(size_t i_src, T val) { set(i_src, val, 0, 0, size); }

    // increment value at index
    void increment(size_t i_src, T val, size_t idx, size_t left_close, size_t right_open) {
        if (right_open - left_close == 1) {
            tree[idx] += val;
            return;
        }

        size_t mid = left_close + (right_open - left_close) / 2;
        if (i_src < mid) increment(i_src, val, 2 * idx + 1, left_close, mid);
        else increment(i_src, val, 2 * idx + 2, mid, right_open);
        tree[idx] = merge(tree[2 * idx + 1], tree[2 * idx + 2]);
    }

    void increment(size_t i_src, T val) { increment(i_src, val, 0, 0, size); }

    // query sum of range [left, right)
    T count(size_t left, size_t right, size_t idx, size_t left_close, size_t right_open) {
        if (left_close >= right or left >= right_open) return DEFAULT;
        if (left_close >= left and right_open <= right) return tree[idx];

        // not fully covered
        size_t mid = left_close + (right_open - left_close) / 2;
        T left_val = count(left, right, 2 * idx + 1, left_close, mid);
        T right_val = count(left, right, 2 * idx + 2, mid, right_open);
        return merge(left_val, right_val);
    }

    T count(size_t left, size_t right) { return count(left, right, 0, 0, size); }
};
