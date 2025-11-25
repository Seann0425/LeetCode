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
    int countUnguarded(size_t m, size_t n, vector<vector<int>> &guards,
                       vector<vector<int>> &walls) {
        // 0 not guarded, 1 guarded, 2 wall, 3 guard
        vector<vector<int>> grid(m, vector<int>(n, 0));
        for (const auto &w : walls) grid[w[0]][w[1]] = 2;
        for (const auto &g : guards) grid[g[0]][g[1]] = 2;
        for (const auto &g : guards) {
            size_t x = g[0], y = g[1];
            // up
            for (size_t i = x - 1; i < m && grid[i][y] < 2; i--) grid[i][y] = 1;
            // down
            for (size_t i = x + 1; i < m && grid[i][y] < 2; i++) grid[i][y] = 1;
            // left
            for (size_t i = y - 1; i < n && grid[x][i] < 2; i--) grid[x][i] = 1;
            // right
            for (size_t i = y + 1; i < n && grid[x][i] < 2; i++) grid[x][i] = 1;
        }
        auto count = 0;
        for (const auto &row : grid)
            count += count_if(row.begin(), row.end(), [](int x) { return x == 0; });
        return count;
    }
};