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

/*the solution should start from below*/

class Solution {
    vector<int> compressed;
    void compress(TreeNode *root) {
        if (!root) return;
        compress(root->left);
        compressed.push_back(root->val);
        compress(root->right);
    }
public:
    bool isValidBST(TreeNode *root) {
        compress(root);
        for (int i = 1; i < static_cast<int>(compressed.size()); i++) {
            if (compressed[i] <= compressed[i - 1]) return false;
        }
        return true;
    }
};