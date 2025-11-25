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
    int minDepth(TreeNode *root) {
        if (!root) return 0;
        if (root->left == nullptr && root->right == nullptr) return 1;
        else if (root->left == nullptr) return minDepth(root->right) + 1;
        else if (root->right == nullptr) return minDepth(root->left) + 1;
        else return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};