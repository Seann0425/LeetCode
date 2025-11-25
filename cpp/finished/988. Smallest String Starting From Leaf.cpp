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
    string smallestString;
    void dfs(TreeNode *currentNode, string currentString) {
        currentString.insert(currentString.begin(), 'a' + currentNode->val);
        if (!currentNode->left && !currentNode->right) {
            if (smallestString.compare(currentString) > 0) smallestString = currentString;
            return;
        }
        if (currentNode->left) dfs(currentNode->left, currentString);
        if (currentNode->right) dfs(currentNode->right, currentString);
    }
public:
    string smallestFromLeaf(TreeNode *root) {
        smallestString = "zzzzzzzzzzzz"s;
        dfs(root, ""s);
        return smallestString;
    }
};