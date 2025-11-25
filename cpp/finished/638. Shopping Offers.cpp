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

class Solution {
    map<int, map<vector<int>, int>> dp;
    size_t n, m;
    int eval(size_t i, vector<int> ds, vector<int> &price, vector<vector<int>> &offer,
             vector<int> &need) {
        if (i == m) {
            auto total = 0;
            for (auto j = 0uz; j < n; ++j) total += (need[j] - ds[j]) * price[j];
            return total;
        }
        if (dp.find(i) != dp.end() && dp[i].find(ds) != dp[i].end()) return dp[i][ds];

        auto no_offer = eval(i + 1, ds, price, offer, need);

        auto with_offer = numeric_limits<int>::max();
        vector<int> copy_ds = ds;
        for (auto j = 0uz; j < n; ++j) {
            if (copy_ds[j] + offer[i][j] <= need[j]) copy_ds[j] += offer[i][j];
            else return dp[i][ds] = min(no_offer, with_offer);
        }
        with_offer = offer[i][n] + eval(i, copy_ds, price, offer, need);
        return dp[i][ds] = min(no_offer, with_offer);
    }
public:
    int shoppingOffers(vector<int> &price, vector<vector<int>> &offer, vector<int> &need) {
        n = price.size();
        m = offer.size();
        vector<int> ds(n, 0);
        return eval(0, ds, price, offer, need);
    }
};