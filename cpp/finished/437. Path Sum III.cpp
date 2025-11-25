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
    long long ans;
    unordered_map<long long, int> prefix_sum_count;
    void dfs(TreeNode *root, long long cur_sum, long long target_sum) {
        if (!root) return;
        cur_sum += root->val;
        ans += prefix_sum_count[cur_sum - target_sum];
        prefix_sum_count[cur_sum]++;
        dfs(root->left, cur_sum, target_sum);
        dfs(root->right, cur_sum, target_sum);
        prefix_sum_count[cur_sum]--;
    }
public:
    int pathSum(TreeNode *root, long long target_sum) {
        ans = 0;
        prefix_sum_count[0] = 1;
        dfs(root, 0, target_sum);
        return ans;
    }
};