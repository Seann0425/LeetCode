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
public:
    vector<int> pivotArray(vector<int> &nums, int pivot) {
        const auto n = nums.size();
        auto ans = vector<int>(n);
        auto i = 0uz;
        for (const auto &x : nums | views::filter([&](const auto &x) { return x < pivot; }))
            ans[i++] = x;
        for (const auto &x : nums | views::filter([&](const auto &x) { return x == pivot; }))
            ans[i++] = x;
        for (const auto &x : nums | views::filter([&](const auto &x) { return x > pivot; }))
            ans[i++] = x;
        return ans;
    }
};

// class Solution {
// public:
//     vector<int> pivotArray(vector<int> &nums, int pivot) {
//         stable_sort(nums.begin(), nums.end(), [&](auto &a, auto &b) {
//             if (a <= pivot and b <= pivot) return a < pivot and b == pivot;
//             return b > pivot and a <= pivot;
//         });
//         return nums;
//     }
// };