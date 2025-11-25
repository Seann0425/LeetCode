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

class Solution {
    using NodePair = tuple<TreeNode *, TreeNode *, int>; // node, parent, cousin_sum
    int get_cousin_sum(TreeNode *node, TreeNode *parent) {
        if (!parent) return node->val;
        return (parent->left ? parent->left->val : 0) + (parent->right ? parent->right->val : 0);
    }
public:
    TreeNode *replaceValueInTree(TreeNode *root) {
        queue<NodePair> bfs;
        bfs.emplace(root, nullptr, root->val);
        vector<int> level_sum;
        while (!bfs.empty()) {
            auto level_size = bfs.size();
            auto sum = 0;
            for (size_t i = 0; i < level_size; i++) {
                auto [node, parent, consin_sum] = bfs.front();
                bfs.pop();
                bfs.emplace(node, parent, consin_sum);
                sum += node->val;
            }
            for (size_t i = 0; i < level_size; i++) {
                auto [node, parent, cousin_sum] = bfs.front();
                bfs.pop();
                node->val = sum - cousin_sum;
                if (node->left) bfs.emplace(node->left, node, get_cousin_sum(node->left, node));
                if (node->right) bfs.emplace(node->right, node, get_cousin_sum(node->right, node));
            }
        }
        return root;
    }
};