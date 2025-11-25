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
    pair<int, int> ans{}; // {max_or, count}
    size_t n;
    void backtracking(vector<int> &nums, size_t idx, int or_val) {
        if (idx == n) return;
        backtracking(nums, idx + 1, or_val);
        or_val |= nums[idx];
        if (or_val > ans.first) ans = {or_val, 1};
        else if (or_val == ans.first) ans.second++;
        backtracking(nums, idx + 1, or_val);
    }
public:
    int countMaxOrSubsets(vector<int> &nums) {
        n = nums.size();
        backtracking(nums, 0, 0);
        return ans.second;
    }
};