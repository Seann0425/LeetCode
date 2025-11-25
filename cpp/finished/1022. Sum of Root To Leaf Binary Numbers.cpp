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
    int sum = 0;
    void traversal(TreeNode *root, int accum, bool sign, int digits) {
        if (digits == 31 && sign) {
            accum += INT_MIN + root->val;
            sum += accum;
            return;
        }
        accum = accum * 2 + root->val;
        digits++;
        if (!root->left && !root->right) sum += accum;
        if (root->left) traversal(root->left, accum, sign, digits);
        if (root->right) traversal(root->right, accum, sign, digits);
        return;
    }
public:
    int sumRootToLeaf(TreeNode *root) {
        traversal(root, 0, root->val, 0);
        return sum;
    }
};