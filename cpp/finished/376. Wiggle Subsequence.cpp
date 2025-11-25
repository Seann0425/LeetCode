#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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

// how does this work
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        const auto n = nums.size();
        int peak = 1, valley = 1;
        for (size_t i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) peak = valley + 1;
            else if (nums[i] < nums[i - 1]) valley = peak + 1;
        }
        return max(valley, peak);
    }
};

// O(n^2)
class Solution {
    typedef pair<int, int> iPair;
public:
    int wiggleMaxLength(vector<int>& nums) {
        const auto n = nums.size();
        vector<iPair> dp(n); // length, ascend or descend
        dp[0] = {1, 0}; // 1 -> last number ascend, -1 -> last number descend
        for (size_t i = 1; i < n; i++) {
            for (size_t j = 0; j < i; j++) {
                if (nums[i] > nums[j] && dp[j].second != 1 && dp[i].first < dp[j].first + 1) {
                    dp[i] = {dp[j].first + 1, 1};
                }
                else if (nums[i] < nums[j] && dp[j].second != -1 && dp[i].first < dp[j].first + 1) {
                    dp[i] = {dp[j].first + 1, -1};
                }
            }
        }
        return max_element(dp.begin(), dp.end())->first;
    }
};