#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Codec {
    TreeNode *construct(istringstream &nodes) {
        string val;
        nodes >> val;
        if (val == "@"s) return nullptr;
        TreeNode *node = new TreeNode(stoi(val));
        node->left = construct(nodes);
        node->right = construct(nodes);
        return node;
    }
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode *root) {
        if (!root) return "@"s;
        return to_string(root->val) + " "s + serialize(root->left) + " "s + serialize(root->right);
    }

    // Decodes your encoded data to tree.
    TreeNode *deserialize(string data) {
        istringstream nodes(data);
        return construct(nodes);
    }
};