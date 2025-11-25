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
    int lengthOfLIS(vector<int> &nums) {
        // O(nlogn)
        vector<int> sub;
        for (const auto &i : nums) {
            auto it = lower_bound(sub.begin(), sub.end(), i);
            if (it == sub.end()) sub.push_back(i);
            else *it = i;
        }
        return static_cast<int>(sub.size());
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int> &nums) {
//         const auto n = nums.size();
//         vector<int> dp(n, 1);
//         for (auto i = 1uz; i < n; i++)
//             for (auto j = 0uz; j < i; j++)
//                 if (nums[j] < nums[i]) dp[i] = max(dp[i], dp[j] + 1);
//         return *max_element(dp.begin(), dp.end());
//     }
// };