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
    void DFS(TreeNode *root, bitset<9> counting, int &ans) {
        counting.flip(root->val - 1);
        if (!root->left && !root->right) {
            if (counting.count() <= 1) ans++;
            return;
        }
        if (root->left) DFS(root->left, counting, ans);
        if (root->right) DFS(root->right, counting, ans);
        return;
    }
public:
    int pseudoPalindromicPaths(TreeNode *root) {
        int ans = 0;
        bitset<9> counting;
        DFS(root, counting, ans);
        return ans;
    }
};