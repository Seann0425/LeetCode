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
    using tuple_t = tuple<int, size_t, size_t>;
    size_t m, n;
    array<int, 5> direc{0, 1, 0, -1, 0};
    bool boundary_check(size_t x, size_t y) { return x < m && y < n; }
public:
    int minTimeToReach(vector<vector<int>> &move_time) {
        m = move_time.size();
        n = move_time[0].size();
        priority_queue<tuple_t, vector<tuple_t>, greater<tuple_t>> asc; // arrival time, x, y
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        asc.emplace(0, 0uz, 0uz);
        visited[0][0] = true;
        while (!asc.empty()) {
            const auto [arrival, x, y] = asc.top();
            asc.pop();
            if (x == m - 1 && y == n - 1) return arrival;
            for (size_t at = 0; at < 4; at++) {
                const auto new_x = x + direc[at], new_y = y + direc[at + 1];
                if (boundary_check(new_x, new_y) && !visited[new_x][new_y]) {
                    visited[new_x][new_y] = true;
                    asc.emplace(max(arrival, move_time[new_x][new_y]) + 1, new_x, new_y);
                }
            }
        }
        return -1;
    }
};