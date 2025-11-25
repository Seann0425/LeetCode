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
    using States = array<int, 16>;
    static constexpr int MOD = 1e9 + 7;
    vector<vector<States>> dp;
    size_t m, n;
    int dfs(const vector<vector<int>> &grid, int k, int x, int y) {
        if (x < 0 or y < 0) return 0;
        if (x == 0 and y == 0) return grid[x][y] == k;
        if (dp[x][y][k] != -1) return dp[x][y][k];
        return dp[x][y][k] = ((x ? dfs(grid, k ^ grid[x][y], x - 1, y) : 0) % MOD +
                              (y ? dfs(grid, k ^ grid[x][y], x, y - 1) : 0) % MOD) %
                             MOD;
    }
public:
    int countPathsWithXorValue(vector<vector<int>> &grid, int k) {
        m = grid.size(), n = grid[0].size();
        States init;
        init.fill(-1);
        dp.resize(m, vector<States>(n, init));
        return dfs(grid, k, m - 1, n - 1);
    }
};