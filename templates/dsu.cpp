#include <bits/stdc++.h>
using namespace std;

class dsu_t {
    vector<size_t> parent;
    vector<size_t> size;
public:
    explicit dsu_t(size_t n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    size_t find(size_t n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    } // path compression

    bool unite(size_t a, size_t b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // already connected
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    size_t size_of(size_t n) { return size[find(n)]; }
};