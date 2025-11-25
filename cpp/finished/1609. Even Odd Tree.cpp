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
    bool isEvenOddTree(TreeNode *root) {
        queue<pair<TreeNode *, bool>> BFS({make_pair(root, false)}); // node, isOdd
        pair<TreeNode *, bool> prevNode(nullptr, true);
        while (!BFS.empty()) {
            pair<TreeNode *, bool> cur = BFS.front();
            BFS.pop();
            if (cur.second == true && cur.first->val % 2 != 0) return false;
            else if (cur.second == false && cur.first->val % 2 != 1) return false;
            if (cur.second == prevNode.second) {
                if (cur.second == true && cur.first->val >= prevNode.first->val) return false;
                if (cur.second == false && cur.first->val <= prevNode.first->val) return false;
            }
            if (cur.first->left) BFS.emplace(cur.first->left, !cur.second);
            if (cur.first->right) BFS.emplace(cur.first->right, !cur.second);
            prevNode = cur;
        }
        return true;
    }
};