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
    using weighted_class = tuple<double, int, int>; // weight, passed, total
public:
    double maxAverageRatio(vector<vector<int>> &classes, int extra_students) {
        const auto n = classes.size();
        auto ans = 0.0;
        priority_queue<weighted_class> pq;
        for (const auto &c : classes) {
            auto weight = static_cast<double>(c[1] - c[0]) / c[1] / (c[1] + 1);
            pq.emplace(weight, c[0], c[1]);
        }
        while (extra_students--) {
            auto [weight, passed, total] = pq.top();
            pq.pop();
            weight = static_cast<double>(total - passed) / (total + 1) / (total + 2);
            pq.emplace(weight, passed + 1, total + 1);
        }
        while (!pq.empty()) {
            auto [weight, passed, total] = pq.top();
            pq.pop();
            ans += static_cast<double>(passed) / total;
        }
        return ans / n;
    }
};