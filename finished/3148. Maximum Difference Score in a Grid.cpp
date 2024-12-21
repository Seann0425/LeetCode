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
    int maxScore(vector<vector<int>> &grid) {
        const auto m = grid.size(), n = grid[0].size();
        vector dp(m, vector<int>(n, 0));
        auto ans = dp[0][0] = numeric_limits<int>::min();
        for (size_t i = 1; i < m; i++)
            ans = max(ans, dp[i][0] = max(0, dp[i - 1][0]) + (grid[i][0] - grid[i - 1][0]));

        for (size_t i = 1; i < n; i++)
            ans = max(ans, dp[0][i] = max(0, dp[0][i - 1]) + (grid[0][i] - grid[0][i - 1]));

        for (size_t i = 1; i < m; i++)
            for (size_t j = 1; j < n; j++)
                ans =
                    max(ans, dp[i][j] = max(max(dp[i - 1][j], 0) + (grid[i][j] - grid[i - 1][j]),
                                            max(dp[i][j - 1], 0) + (grid[i][j] - grid[i][j - 1])));

        return ans;
    }
};