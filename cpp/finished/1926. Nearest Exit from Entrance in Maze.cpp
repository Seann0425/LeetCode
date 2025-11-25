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
    array<int, 5> direc{0, 1, 0, -1, 0};
    using Coordinate = pair<size_t, size_t>;
    bool boundary_check(size_t x, size_t y, size_t m, size_t n) { return x < m && y < n; }
public:
    int nearestExit(vector<vector<char>> &maze, vector<int> &entrance) {
        const auto m = maze.size(), n = maze[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (maze[i][j] == '+') visited[i][j] = true;
            }
        }

        queue<Coordinate> bfs;
        bfs.emplace(entrance[0], entrance[1]);
        visited[entrance[0]][entrance[1]] = true;
        auto steps = 0;
        while (!bfs.empty()) {
            for (size_t i = bfs.size(); i > 0; i--) {
                auto [x, y] = bfs.front();
                bfs.pop();
                if (steps && (!x or !y or x == m - 1 or y == n - 1)) return steps;

                for (size_t at = 0; at < 4; at++) {
                    auto new_x = x + direc[at], new_y = y + direc[at + 1];
                    if (boundary_check(new_x, new_y, m, n) && !visited[new_x][new_y]) {
                        visited[new_x][new_y] = true;
                        bfs.emplace(new_x, new_y);
                    }
                }
            }
            steps += 1;
        }
        return -1;
    }
};