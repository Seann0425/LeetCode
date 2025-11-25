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
    long long maxPoints(vector<vector<int>> &points) {
        const auto m = points.size(), n = points.front().size();
        vector<vector<long long>> dp(m, vector<long long>(n));
        copy(points.front().begin(), points.front().end(), dp.front().begin());
        for (size_t i = 1; i < m; i++) {
            long long best = -1;
            // from left
            for (size_t j = 0; j < n; j++)
                dp[i][j] = points[i][j] + (best = max(best - 1, dp[i - 1][j]));
            // from right
            best = -1;
            for (size_t j = n - 1; j < n; j--)
                dp[i][j] = max(dp[i][j], points[i][j] + (best = max(best - 1, dp[i - 1][j])));
        }
        return *max_element(dp.back().begin(), dp.back().end());
    }
};