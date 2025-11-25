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
    using Coordinate = pair<size_t, size_t>;
    using Path = tuple<int, size_t, size_t>; // obstacle removed, x, y
    array<int, 5> direc{0, -1, 0, 1, 0};
public:
    int minimumObstacles(vector<vector<int>> &grid) {
        const auto n = grid.size(), m = grid[0].size();
        vector<vector<char>> visited(n, vector<char>(m, false));
        priority_queue<Path, vector<Path>, greater<Path>> obstacle_asc;
        obstacle_asc.emplace(0, 0uz, 0uz);
        visited[0][0] = true;
        while (!obstacle_asc.empty()) {
            const auto [obstacle_removed, x, y] = obstacle_asc.top();
            obstacle_asc.pop();
            if (x == n - 1 && y == m - 1) return obstacle_removed;
            for (size_t at = 0; at < 4; at++) {
                const auto new_x = x + direc[at], new_y = y + direc[at + 1];
                if (new_x >= n or new_y >= m or visited[new_x][new_y]) continue;
                visited[new_x][new_y] = true;
                obstacle_asc.emplace(grid[new_x][new_y] ? obstacle_removed + 1 : obstacle_removed,
                                     new_x, new_y);
            }
        }
        return -1;
    }
};