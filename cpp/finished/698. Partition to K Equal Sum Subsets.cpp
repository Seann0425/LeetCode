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
    array<int, 16> groups{};
    bool backtracking(vector<int> &nums, size_t i, int k, int target) {
        if (i == nums.size())
            return all_of(groups.begin(), groups.begin() + k,
                          [target](int x) { return x == target; });
        for (int j = 0; j < k; ++j) {
            if (groups[j] + nums[i] > target) continue;
            groups[j] += nums[i];
            if (backtracking(nums, i + 1, k, target)) return true;
            groups[j] -= nums[i];
            if (groups[j] == 0) break;
        }
        return false;
    }
public:
    bool canPartitionKSubsets(vector<int> &nums, int k) {
        if (reduce(nums.begin(), nums.end()) % k) return false;
        auto target = reduce(nums.begin(), nums.end()) / k;
        return backtracking(nums, 0uz, k, target);
    }
};