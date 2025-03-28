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

class Solution {
    size_t n;
    bool check(const vector<int> &nums, int p, int m) {
        if (!p) return true;
        auto cnt = 0;
        for (auto i = 1uz; i < n; ++i)
            if (nums[i] - nums[i - 1] <= m) {
                ++cnt;
                ++i;
            }
        return cnt >= p;
    }
public:
    int minimizeMax(vector<int> &nums, int p) {
        n = nums.size();
        sort(nums.begin(), nums.end());
        auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        auto l = 0, r = *mx - *mn;
        while (l < r) {
            const auto m = l + (r - l) / 2;
            // check if it's possible to pick p pairs with max difference <= m
            if (check(nums, p, m)) r = m;
            else l = m + 1;
        }
        return l;
    }
};