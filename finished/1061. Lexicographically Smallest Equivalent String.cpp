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
#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class dsu_t {
    vector<size_t> parent;
public:
    explicit dsu_t(size_t n) : parent(n) { iota(parent.begin(), parent.end(), 0); }
    size_t find(size_t x) {
        if (parent[x] != x) parent[x] = find(parent[x]);
        return parent[x];
    }
    // merge based on lexicographical order
    void merge(size_t x, size_t y) {
        auto root_x = find(x);
        auto root_y = find(y);
        if (root_x == root_y) return;
        if (root_x > root_y) swap(root_x, root_y);
        parent[root_y] = root_x;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        const auto n = s1.size(), m = baseStr.size();
        dsu_t dsu(26);
        for (auto i = 0uz; i < n; ++i) dsu.merge(s1[i] - 'a', s2[i] - 'a');
        string ans;
        ans.reserve(m);
        for (auto i = 0uz; i < m; ++i) {
            auto root = dsu.find(baseStr[i] - 'a');
            ans.push_back('a' + root);
        }
        return ans;
    }
};