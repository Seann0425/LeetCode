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

#pragma GCC optimize("O3", "unroll-loops")
static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
    using tuple_t = tuple<int, size_t, size_t>; // dist, x, y
    using pq_t = priority_queue<tuple_t, vector<tuple_t>, greater<tuple_t>>;
    template <typename T>
    using grid_t = vector<vector<T>>;
    const int inf = 0x3f3f3f3f;
    array<int, 5> direc = {0, 1, 0, -1, 0};
public:
    int minTimeToReach(vector<vector<int>> &move_time) {
        const auto n = move_time.size(), m = move_time[0].size();
        grid_t<int> dist(n, vector<int>(m, inf));
        grid_t<bool> visited(n, vector<bool>(m, false));
        pq_t pq;
        pq.emplace(0, 0, 0);
        dist[0][0] = 0;

        while (!pq.empty()) {
            auto [d, x, y] = pq.top();
            pq.pop();
            if (visited[x][y]) continue;
            if (x == n - 1 and y == m - 1) break;
            visited[x][y] = true;
            for (auto at = 0uz; at < 4uz; ++at) {
                const auto nx = x + direc[at], ny = y + direc[at + 1];
                if (nx >= n or ny >= m) continue;
                auto distance = max(dist[x][y], move_time[nx][ny]) + (x + y) % 2 + 1;
                if (distance < dist[nx][ny]) {
                    dist[nx][ny] = distance;
                    pq.emplace(distance, nx, ny);
                }
            }
        }

        return dist[n - 1][m - 1];
    }
};