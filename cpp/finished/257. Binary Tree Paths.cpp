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
    vector<string> paths;
    void plant(TreeNode *root, string path) {
        path = path + "->" + to_string(root->val);
        if (!root->left && !root->right) {
            paths.push_back(path);
            return;
        }
        if (root->left) plant(root->left, path);
        if (root->right) plant(root->right, path);
        return;
    }
    vector<string> binaryTreePaths(TreeNode *root) {
        if (!root->left && !root->right) {
            paths.push_back(to_string(root->val));
            return paths;
        }
        if (root->left) plant(root->left, to_string(root->val));
        if (root->right) plant(root->right, to_string(root->val));
        return paths;
    }
};