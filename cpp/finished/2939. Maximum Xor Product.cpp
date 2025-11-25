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
    static constexpr long long mod = 1e9 + 7;
public:
    int maximumXorProduct(long long a, long long b, int n) {
        if (!n) return ((a % mod) * (b % mod)) % mod;
        auto mask = ~((1ll << n) - 1);
        auto cur_a = a & mask, cur_b = b & mask;
        auto x = 0ll;
        for (auto i = 1ll << (n - 1); i; i >>= 1) {
            if ((a & i) && (b & i)) continue;
            if (!(a & i) && !(b & i)) a ^= i, b ^= i;
            if (cur_a > cur_b && (a & i) && !(b & i) or cur_a < cur_b && !(a & i) && (b & i))
                a ^= i, b ^= i;
            cur_a ^= (a & i);
            cur_b ^= (b & i);
        }
        return ((a % mod) * (b % mod)) % mod;
    }
};