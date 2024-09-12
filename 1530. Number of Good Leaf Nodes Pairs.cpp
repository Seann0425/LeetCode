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

constexpr size_t max_distance = 11;

class Solution {
    int ans;
    size_t dist;
    vector<int> dfs(TreeNode *node) {
        if (!node) return {};
        if (!node->left and !node->right) return {1};
        vector<int> children_dist(max_distance);
        vector<int> left(dfs(node->left)), right(dfs(node->right));
        if (left.size() == 1) children_dist[1]++;
        else if (left.size() == max_distance)
            for (size_t i = 0; i < max_distance - 1; i++) children_dist[i + 1] += left[i];
        if (right.size() == 1) children_dist[1]++;
        else if (right.size() == max_distance)
            for (size_t i = 0; i < max_distance - 1; i++) children_dist[i + 1] += right[i];
        two_sum(children_dist);
        return std::move(children_dist);
    }
    void two_sum(const vector<int> &children_dist) {
        // to be optimized
        for (size_t i = 1; i < max_distance - 2; i++) {
            for (size_t j = i; j < max_distance - 2; j++) {
                if (i + j > dist) continue;
                ans += static_cast<int>(i == j ? children_dist[i] * (children_dist[i] - 1)
                                               : children_dist[j] * children_dist[i]);
            }
        }
    }
public:
    int countPairs(TreeNode *root, int distance) {
        dist = static_cast<size_t>(distance);
        ans = 0;
        dfs(root);
        return ans;
    }
};