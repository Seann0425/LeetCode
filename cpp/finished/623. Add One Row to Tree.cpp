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
    TreeNode *addOneRow(TreeNode *root, int val, int depth) {
        if (depth == 1) {
            TreeNode *node = new TreeNode(val, root, nullptr);
            return node;
        }
        queue<pair<TreeNode *, int>> bfs;
        bfs.emplace(root, 1);
        while (!bfs.empty()) {
            auto [cur, level] = bfs.front();
            bfs.pop();
            if (level < depth - 1) {
                if (cur->left) bfs.emplace(cur->left, level + 1);
                if (cur->right) bfs.emplace(cur->right, level + 1);
            } else {
                TreeNode *lnode = new TreeNode(val, cur->left, nullptr);
                cur->left = lnode;
                TreeNode *rnode = new TreeNode(val, nullptr, cur->right);
                cur->right = rnode;
            }
        }
        return root;
    }
};