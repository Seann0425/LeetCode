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

class Solution {
    vector<int> traverse;
    void inorder(TreeNode* node) {
        if (!node) return;
        inorder(node->left);
        traverse.push_back(node->val);
        inorder(node->right);
    }
    TreeNode* buildTree(size_t left, size_t right) {
        if (right == numeric_limits<size_t>::max() || right < left) return nullptr;
        size_t mid = left + (right - left) / 2;
        return new TreeNode(traverse[mid], buildTree(left, mid - 1), buildTree(mid + 1, right));
    }
public:
    TreeNode* balanceBST(TreeNode* root) {
        inorder(root);
        return buildTree(0ULL, traverse.size() - 1);
    }
};