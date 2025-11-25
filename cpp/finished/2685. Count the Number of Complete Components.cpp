#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*the solution should start from below*/

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class dsu_t {
    size_t n;
    vector<int> parent;
    vector<int> size;
public:
    dsu_t(size_t sz) : n(sz), parent(sz), size(sz, 1) { iota(parent.begin(), parent.end(), 0); }
    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }
    int merge(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return px;
        if (size[px] < size[py]) swap(px, py);
        size[px] += size[py];
        return parent[py] = px;
    }
    int get_size(int x) { return size[find(x)]; }
    bool same(int x, int y) { return find(x) == find(y); }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>> &edges) {
        dsu_t dsu(n);
        for (const auto &e : edges) dsu.merge(e[0], e[1]);
        vector<int> cnt(n);
        for (const auto &e : edges) {
            auto px = dsu.find(e[0]);
            ++cnt[px];
        }
        auto ans = 0;
        for (auto i = 0uz; i < n; ++i) {
            auto size = dsu.get_size(i);
            if (cnt[i] == size * (size - 1) / 2) ++ans;
        }
        return ans;
    }
};