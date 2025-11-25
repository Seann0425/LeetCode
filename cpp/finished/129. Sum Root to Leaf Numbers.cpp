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
    int sum;
    void helper(TreeNode *node, int prev) {
        prev = prev * 10 + node->val;
        if (!node->left && !node->right) {
            sum += prev;
            return;
        }
        if (node->left) helper(node->left, prev);
        if (node->right) helper(node->right, prev);
    }
public:
    int sumNumbers(TreeNode *root) {
        sum = 0;
        helper(root, 0);
        return sum;
    }
};