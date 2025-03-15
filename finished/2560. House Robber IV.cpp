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
    bool valid(const vector<int> &nums, int mid, int k) {
        // greedy
        // if there's an optimal solution with a[i] to be the first element of the sequence
        // change a[i] to some elemnt a[j] where j < i will not affect the result
        const auto n = nums.size();
        for (auto i = 0uz; i < n; ++i) {
            if (nums[i] > mid) continue;
            if (--k == 0) return true;
            ++i;
        }
        return false;
    }
public:
    int minCapability(vector<int> &nums, int k) {
        auto [mn, mx] = minmax_element(nums.begin(), nums.end());
        auto l = *mn, r = *mx;
        while (l < r) {
            auto mid = l + (r - l) / 2;
            if (valid(nums, mid, k)) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};