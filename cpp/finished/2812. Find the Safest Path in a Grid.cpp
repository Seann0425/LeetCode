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
    size_t n;
    array<int, 5> direc{0, 1, 0, -1, 0};
    bool boundary_check(size_t x, size_t y) { return x < n && y < n; }
    void distance2thief(const vector<vector<int>> &grid, vector<vector<int>> &dist) {
        // thieves position
        queue<pair<size_t, size_t>> bfs;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (grid[i][j]) {
                    dist[i][j] = 0;
                    bfs.emplace(i, j);
                }
            }
        }
        // bfs
        while (!bfs.empty()) {
            auto [x, y] = bfs.front();
            auto safeness = dist[x][y];
            bfs.pop();
            for (size_t at = 0; at < 4; at++) {
                auto x_new = x + direc[at], y_new = y + direc[at + 1];
                if (boundary_check(x_new, y_new) && 1 + safeness < dist[x_new][y_new]) {
                    dist[x_new][y_new] = 1 + safeness;
                    bfs.emplace(x_new, y_new);
                }
            }
        }
    }
    int compute_safeness(const vector<vector<int>> &dist) {
        // bfs routes in a safeness-descending way
        priority_queue<tuple<int, size_t, size_t>> desc; // safeness, x, y
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        desc.emplace(dist[0][0], 0uz, 0uz);
        visited[0][0] = true;
        while (!desc.empty()) {
            auto [safeness, x, y] = desc.top();
            desc.pop();
            if (x == n - 1 && y == n - 1) return safeness;
            for (size_t at = 0; at < 4; at++) {
                auto x_new = x + direc[at], y_new = y + direc[at + 1];
                if (boundary_check(x_new, y_new) && !visited[x_new][y_new]) {
                    visited[x_new][y_new] = true;
                    desc.emplace(min(safeness, dist[x_new][y_new]), x_new, y_new);
                }
            }
        }
        return -1; // error
    }
public:
    int maximumSafenessFactor(vector<vector<int>> &grid) {
        n = grid.size();
        vector<vector<int>> distance(n, vector<int>(n, numeric_limits<int>::max()));
        distance2thief(grid, distance);
        return compute_safeness(distance);
    }
};