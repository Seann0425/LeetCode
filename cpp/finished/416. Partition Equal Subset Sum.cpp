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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    bool canPartition(vector<int> &nums) {
        auto sum = reduce(nums.begin(), nums.end());
        if (sum & 1) return false;
        bitset<20005> subset_sum{1};
        for (const auto &i : nums) subset_sum |= subset_sum << i;
        return subset_sum[sum / 2];
    }
};

// class Solution {
//     vector<vector<char>> dp;
//     size_t n;
//     bool subset_sum(vector<int> &nums, size_t i, int sum) {
//         if (i >= n) return 0;
//         if (!sum) return dp[i][sum] = 1;
//         if (dp[i][sum] != -1) return dp[i][sum];
//         if (nums[i] > sum) return dp[i][sum] = subset_sum(nums, i - 1, sum);
//         return dp[i][sum] = subset_sum(nums, i - 1, sum) or subset_sum(nums, i - 1, sum -
//         nums[i]);
//     }
// public:
//     bool canPartition(vector<int> &nums) {
//         auto sum = reduce(nums.begin(), nums.end());
//         if (sum & 1) return false;
//         n = nums.size();
//         dp.resize(n, vector<char>(sum / 2 + 1, -1));
//         return subset_sum(nums, n - 1, sum / 2);
//     }
// };