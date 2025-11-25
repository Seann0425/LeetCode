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
    vector<int> preorder, inorder;
    unordered_map<int, size_t> in_idx;
    size_t n;
    TreeNode *divide_conquer(size_t in_l, size_t in_r, size_t pre) {
        if (in_l > in_r or in_r >= n or pre >= n) return nullptr;
        auto *root = new TreeNode(preorder[pre]);
        auto in_m = in_idx[root->val];
        root->left = divide_conquer(in_l, in_m - 1, pre + 1);
        root->right = divide_conquer(in_m + 1, in_r, pre + in_m - in_l + 1);
        return root;
    }
public:
    TreeNode *buildTree(vector<int> &pre_order, vector<int> &in_order) {
        preorder = std::move(pre_order);
        inorder = std::move(in_order);
        n = inorder.size();
        for (size_t i = 0; i < n; i++) in_idx[inorder[i]] = i;
        return divide_conquer(0, n - 1, 0);
    }
};