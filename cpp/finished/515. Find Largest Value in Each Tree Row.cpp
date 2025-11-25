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
public:
    vector<int> largestValues(TreeNode *root) {
        if (!root) return {};
        vector<int> ans;
        queue<TreeNode *> bfs;
        bfs.push(root);
        while (!bfs.empty()) {
            auto size = bfs.size();
            auto max_val = numeric_limits<int>::min();
            for (auto i = 0uz; i < size; i++) {
                auto node = bfs.front();
                bfs.pop();
                max_val = max(max_val, node->val);
                if (node->left) bfs.push(node->left);
                if (node->right) bfs.push(node->right);
            }
            ans.push_back(max_val);
        }
        return ans;
    }
};