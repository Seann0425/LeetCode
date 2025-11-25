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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> seq1, seq2;
        seqGenerator(root1, seq1);
        seqGenerator(root2, seq2);
        return sameSeq(seq1, seq2);
    }

    void seqGenerator(TreeNode *root, vector<int> &seq) {
        if (!root->left && !root->right) {
            seq.push_back(root->val);
            return;
        }
        if (root->left) seqGenerator(root->left, seq);
        if (root->right) seqGenerator(root->right, seq);
        return;
    }

    bool sameSeq(vector<int> &seq1, vector<int> &seq2) {
        if (seq1.size() != seq2.size()) return false;
        for (int i = 0; i < seq1.size(); i++)
            if (seq1[i] != seq2[i]) return false;
        return true;
    }
};