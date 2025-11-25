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
    using Cell = tuple<int, size_t, size_t>;
    static constexpr array<int, 5> direction{0, 1, 0, -1, 0};
public:
    int minimumTime(vector<vector<int>> &grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;
        const auto m = grid.size(), n = grid[0].size();
        vector<vector<int>> time(m, vector<int>(n, numeric_limits<int>::max()));
        priority_queue<Cell, vector<Cell>, greater<>> dijkstra;
        dijkstra.emplace(0, 0uz, 0uz);
        while (!dijkstra.empty()) {
            const auto [cost, x, y] = dijkstra.top();
            dijkstra.pop();
            if (x == m - 1 && y == n - 1) return cost;
            for (size_t at = 0; at < 4; at++) {
                const auto new_x = x + direction[at], new_y = y + direction[at + 1];
                if (new_x >= m or new_y >= n) continue;
                const auto new_cost =
                    max(cost + 1, grid[new_x][new_y] + (grid[new_x][new_y] - cost + 1) % 2);
                if (new_cost < time[new_x][new_y])
                    dijkstra.emplace(time[new_x][new_y] = new_cost, new_x, new_y);
            }
        }
        return -1;
    }
};