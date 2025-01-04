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

// dp
class Solution {
    array<array<int, 2005>, 25>
        dp{}; // dp[i][j] = number of ways to get sum j using first i elements
    int top_down(const vector<int> &nums, size_t i, int sum) {
        if (sum < 0) return 0; // out of target constraint
        if (!i) return sum == 1000;
        if (dp[i][sum] != -1) return dp[i][sum];
        return dp[i][sum] = top_down(nums, i - 1, sum - nums[i - 1]) +
                            top_down(nums, i - 1, sum + nums[i - 1]);
    }
public:
    int findTargetSumWays(vector<int> &nums, int target) {
        for (auto &row : dp) row.fill(-1);
        return top_down(nums, nums.size(), target + 1000);
    }
};

// backtracking O(2^n)
// class Solution {
//     int ans, target;
//     void backtracking(vector<int> &nums, size_t i, int cur) {
//         if (i == nums.size()) {
//             ans += (cur == target);
//             return;
//         }
//         backtracking(nums, i + 1, cur + nums[i]);
//         backtracking(nums, i + 1, cur - nums[i]);
//     }
// public:
//     int findTargetSumWays(vector<int> &nums, int target) {
//         ans = 0;
//         this->target = target;
//         backtracking(nums, 0, 0);
//         return ans;
//     }
// };