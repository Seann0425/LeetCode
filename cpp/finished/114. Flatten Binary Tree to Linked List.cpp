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
public:
    void flatten(TreeNode *root) {
        if (!root) return;
        stack<TreeNode *> preorder;
        vector<TreeNode *> tmp;
        preorder.emplace(root);
        while (!preorder.empty()) {
            TreeNode *cur = preorder.top();
            preorder.pop();
            if (cur->right) preorder.push(cur->right);
            if (cur->left) preorder.push(cur->left);
            tmp.push_back(cur);
        }
        tmp.push_back(nullptr);
        for (int i = 0; i < static_cast<int>(tmp.size()) - 1; i++) {
            tmp[i]->left = nullptr;
            tmp[i]->right = tmp[i + 1];
        }
        return;
    }
};