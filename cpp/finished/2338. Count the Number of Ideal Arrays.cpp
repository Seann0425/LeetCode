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

static constexpr size_t max_n = 1e4 + 5;
static constexpr int mod = 1e9 + 7;
static constexpr int max_p = 15; // 2 ^ 15 > 1e4
array<array<int, max_p + 1>, max_n + max_p> c{};
array<vector<int>, max_n> ps{};
array<int, max_n> sieve;

class Solution {
public:
    Solution() {
        if (c[0][0]) return;
        // minimum prime factor sieve
        for (int i = 2; i < max_n; ++i) {
            if (sieve[i]) continue;
            for (int j = i; j < max_n; j += i) sieve[j] = i;
        }
        // prime factorization
        for (int i = 2; i < max_n; ++i) {
            int x = i;
            while (x > 1) {
                int p = sieve[x], cnt = 0;
                while (!(x % p)) {
                    x /= p;
                    ++cnt;
                }
                ps[i].push_back(cnt);
            }
        }
        c[0][0] = 1;
        for (int i = 1; i < max_n + max_p; ++i) {
            c[i][0] = 1;
            for (int j = 1; j <= min(i, max_p); ++j) {
                c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;
            }
        }
    }
    int idealArrays(int n, int max_value) {
        auto ans = 0ll;
        for (auto x = 1; x <= max_value; ++x) {
            auto mul = 1ll;
            for (auto p : ps[x]) mul = mul * c[n + p - 1][p] % mod;
            ans = (ans + mul) % mod;
        }
        return ans;
    }
};