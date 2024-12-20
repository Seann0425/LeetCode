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
    TreeNode *reverseOddLevels(TreeNode *root) {
        if (!root) return root;
        queue<TreeNode *> bfs;
        bfs.push(root);
        auto is_odd = false;
        while (!bfs.empty()) {
            const auto size = bfs.size();
            vector<TreeNode *> level(size);
            for (auto i = 0uz; i < size; i++) {
                level[i] = bfs.front();
                bfs.pop();
                if (level[i]->left) bfs.push(level[i]->left);
                if (level[i]->right) bfs.push(level[i]->right);
            }
            if (is_odd)
                for (size_t i = 0; i < size / 2; i++) swap(level[i]->val, level[size - i - 1]->val);
            is_odd = !is_odd;
        }
        return root;
    }
};