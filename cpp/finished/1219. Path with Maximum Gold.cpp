#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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
// static const auto __ = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
    int ans;
    void workerIntelligence(size_t i, size_t j, array<bitset<15>, 15> visited, const vector<vector<int>> &grid, int collected) {
        collected += grid[i][j];
        visited[i][j] = true;
        ans = max(ans, collected);
        // worker's intelligence
        if (i > 0 && grid[i - 1][j] != 0 && !visited[i - 1][j]) workerIntelligence(i - 1, j, visited, grid, collected);
        if (i < grid.size() - 1 && grid[i + 1][j] != 0 && !visited[i + 1][j]) workerIntelligence(i + 1, j, visited, grid, collected);
        if (j > 0 && grid[i][j - 1] != 0 && !visited[i][j - 1]) workerIntelligence(i, j - 1, visited, grid, collected);
        if (j < grid.front().size() - 1 && grid[i][j + 1] != 0 && !visited[i][j + 1]) workerIntelligence(i, j + 1, visited, grid, collected);
    }
    int checkFilled(const vector<vector<int>> &grid) {
        int consecutive = 0;
        for (const auto &row : grid) {
            for (const auto &gold : row) {
                if (!gold) return 0;
                consecutive += gold;
            }
        }
        return consecutive;
    }
public:
    int getMaximumGold(vector<vector<int>> &grid) {
        ans = checkFilled(grid);
        if (ans != 0) return ans;
        const auto M = grid.size();
        const auto N = grid.front().size();
        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                if (!grid[i][j]) continue;
                array<bitset<15>, 15> visited{};
                workerIntelligence(i, j, visited, grid, 0);
            }
        }
        return ans;
    }
};