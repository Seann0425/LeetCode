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
    array<int, 100005> max_height_rm;
    int max_height{};
    void dfs_left(TreeNode *node, int cur_height) {
        if (!node) return;
        max_height_rm[static_cast<size_t>(node->val)] = max_height;
        max_height = max(max_height, cur_height);
        dfs_left(node->left, cur_height + 1);
        dfs_left(node->right, cur_height + 1);
    }
    void dfs_right(TreeNode *node, int cur_height) {
        if (!node) return;
        max_height_rm[static_cast<size_t>(node->val)] =
            max(max_height, max_height_rm[static_cast<size_t>(node->val)]);
        max_height = max(max_height, cur_height);
        dfs_right(node->right, cur_height + 1);
        dfs_right(node->left, cur_height + 1);
    }
public:
    vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
        vector<int> ans;
        ans.reserve(queries.size());
        dfs_left(root, 0);
        max_height = 0;
        dfs_right(root, 0);
        for (const auto &q : queries) ans.push_back(max_height_rm[static_cast<size_t>(q)]);
        return ans;
    }
};