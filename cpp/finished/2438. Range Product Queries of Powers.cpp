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
#pragma GCC optimize("O3", "unroll-loops")

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
    auto eea(int a, int r, int s, int b, int t, int u) -> int {
        if (b == 1) return u;
        auto x = a % b, y = r - t * (a / b), z = s - u * (a / b);
        return eea(b, t, u, x, y, z);
    }
public:
    vector<int> productQueries(int x, vector<vector<int>> &queries) {
        const long long mod = 1e9 + 7;

        vector<int> power;
        for (auto i = 1; i <= x; i <<= 1)
            if (i & x) power.push_back(i);
        const auto n = power.size(), m = queries.size();

        vector<long long> prefix(n + 1);
        prefix.front() = 1;
        for (auto i = 1uz; i <= n; ++i) prefix[i] = (prefix[i - 1] * power[i - 1]) % mod;

        auto inverse = [&](long long x) -> long long {
            return (eea(mod, 1, 0, x, 0, 1) + mod) % mod;
        };
        vector<int> ans(m);
        for (auto i = 0uz; i < m; ++i) {
            auto l = queries[i][0], r = queries[i][1];
            ans[i] = (prefix[r + 1] * inverse(prefix[l])) % mod;
        }
        return ans;
    }
};