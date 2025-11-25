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

class Solution {
public:
    int minCompare(TreeNode *root, int mn) {
        if (!root->left) return INT_MAX;
        if (root->left->val == root->right->val) {
            return min(minCompare(root->left, mn), minCompare(root->right, mn));
        } else if (root->left->val == mn) return min(minCompare(root->left, mn), root->right->val);
        else return min(root->left->val, minCompare(root->right, mn));
    }

    int findSecondMinimumValue(TreeNode *root) {
        if (root->val == INT_MAX) return -1;
        int peer = minCompare(root, root->val);
        if (peer == INT_MAX && root->left && (root->left->val == INT_MAX || root->right->val == INT_MAX)) {
            return INT_MAX;
        }
        return (peer == INT_MAX) ? (-1) : peer;
    }
};