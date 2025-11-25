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
    TreeNode *P1, *P2;
    int D1, D2;
    void find(TreeNode *root, int depth, TreeNode *parent, int target, TreeNode **P, int *D) {
        if (!root) return;
        depth++;
        parent = root;
        if (root->left and root->left->val == target) {
            *D = depth;
            *P = parent;
            return;
        } else find(root->left, depth, parent, target, P, D);
        if (root->right and root->right->val == target) {
            *D = depth;
            *P = parent;
            return;
        } else find(root->right, depth, parent, target, P, D);
        return;
    }
public:
    bool isCousins(TreeNode *root, int x, int y) {
        find(root, 0, nullptr, x, &P1, &D1);
        find(root, 0, nullptr, y, &P2, &D2);
        return (P1 != P2) and (D1 == D2);
    }
};