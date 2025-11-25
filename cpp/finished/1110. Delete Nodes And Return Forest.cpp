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

constexpr size_t n = 1005;

class Solution {
    vector<TreeNode*> trees;
    bitset<n> delete_table;
    // return deleted or not
    bool dfs(TreeNode* node, bool is_root) {
        if (!node) return true;
        bool deleted = delete_table.test(static_cast<size_t>(node->val));
        if (dfs(node->left, deleted)) node->left = nullptr;
        if (dfs(node->right, deleted)) node->right = nullptr;
        if (is_root and !deleted) trees.push_back(node);
        if (deleted) delete node;
        return deleted;
    }
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        if (to_delete.empty()) return {root};
        for (const auto &i : to_delete) delete_table.set(static_cast<size_t>(i));
        TreeNode *tmp_root = new TreeNode(to_delete.front(), root, nullptr);
        dfs(tmp_root, true);
        return trees;
    }
};