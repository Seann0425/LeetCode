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
    auto build_tree(int left, int right) -> vector<TreeNode *> {
        if (left == right) return {new TreeNode(left)};
        vector<TreeNode *> combinitions;
        for (int i = left; i <= right; i++) {
            auto root = new TreeNode(i);
            vector<TreeNode *> left_comb(build_tree(left, i - 1));
            vector<TreeNode *> right_comb(build_tree(i + 1, right));

            for (const auto &const left_node : left_comb) {
                for (const auto &const right_node : right_comb) {
                    combinitions.push_back(new TreeNode(i, left_node, right_node));
                }
            }
        }
        return combinitions;
    }
public:
    vector<TreeNode *> generateTrees(int n) { return build_tree(1, n); }
};