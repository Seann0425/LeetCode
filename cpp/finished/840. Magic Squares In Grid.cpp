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
    using grid_t = vector<vector<int>>;
    bool candidate_check(const grid_t &grid, size_t i, size_t j) {
        if (grid[i][j] != 5) return false;
        if (grid[i - 1][j - 1] & 1 || grid[i + 1][j + 1] & 1) return false;
        if (grid[i - 1][j + 1] & 1 || grid[i + 1][j - 1] & 1) return false;
        return true;
    }
    bool is_magic(const grid_t &g, size_t i, size_t j) {
        for (int row = -1; row <= 1; row++)
            if (g[i + row][j - 1] + g[i + row][j] + g[i + row][j + 1] != 15) return false;
        for (int col = -1; col <= 1; col++)
            if (g[i - 1][j + col] + g[i][j + col] + g[i + 1][j + col] != 15) return false;
        if (g[i - 1][j - 1] + g[i + 1][j + 1] != 10) return false;
        if (g[i - 1][j + 1] + g[i + 1][j - 1] != 10) return false;
        return true;
    }
public:
    int numMagicSquaresInside(grid_t &grid) {
        const auto m = grid.size(), n = grid[0].size();
        auto ans = 0;
        for (size_t i = 1; i < m - 1; i++) {
            for (size_t j = 1; j < n - 1; j++) {
                if (candidate_check(grid, i, j) && is_magic(grid, i, j)) ans++;
            }
        }
        return ans;
    }
};