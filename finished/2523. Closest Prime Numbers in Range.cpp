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

static constexpr size_t max_n = 1000005;
static const bitset<max_n> primes = []() {
    bitset<max_n> primes{};
    primes.set();
    primes[0] = primes[1] = false;
    for (auto i = 2uz; i * i < max_n; ++i)
        if (primes[i])
            for (auto j = i * i; j < max_n; j += i) primes[j] = false;
    return primes;
}();

class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<int> ans{-1, -1};
        auto min_diff = numeric_limits<int>::max(), prev = -1;
        for (auto i = left; i <= right; ++i) {
            if (!primes[i]) continue;
            if (prev == -1) {
                prev = i;
                continue;
            }
            if (i - prev < min_diff) {
                min_diff = i - prev;
                ans = {prev, i};
            }
            prev = i;
        }
        return ans;
    }
};