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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) return false;
        if (!root->left && !root->right) {
            switch (targetSum - root->val) {
            case 0:
                return true;
                break;
            default:
                return false;
                break;
            }
        } else if (!root->left) {
            if (hasPathSum(root->right, targetSum - root->val)) return true;
            else return false;
        } else if (!root->right) {
            if (hasPathSum(root->left, targetSum - root->val)) return true;
            else return false;
        }
        if (hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val)) return true;
        return false;
    }
};