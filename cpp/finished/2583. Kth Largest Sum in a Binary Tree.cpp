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
    long long kthLargestLevelSum(TreeNode *root, size_t k) {
        using LabeledNode = pair<TreeNode *, size_t>;
        queue<LabeledNode> bfs;
        vector<long long> level_sum;
        bfs.emplace(root, 0);
        while (!bfs.empty()) {
            auto [node, level] = bfs.front();
            bfs.pop();
            if (level_sum.size() <= level) level_sum.push_back(node->val);
            else level_sum[level] += node->val;
            if (node->left) bfs.emplace(node->left, level + 1);
            if (node->right) bfs.emplace(node->right, level + 1);
        }
        // use quick select or order statistics to optimize this
        // sort(level_sum.begin(), level_sum.end(), greater<>());
        // return level_sum.size() >= k ? level_sum[k - 1] : -1LL;

        return level_sum.size() >= k ? nth_element(level_sum.begin(), level_sum.begin() + k - 1,
                                                   level_sum.end(), greater<>()),
               level_sum[k - 1]      : -1LL;
    }
};