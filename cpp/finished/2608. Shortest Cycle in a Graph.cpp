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
    using graph_t = vector<vector<int>>;
    graph_t adj;
    int ans = numeric_limits<int>::max();
    void build_adj(size_t n, const graph_t &edges) {
        adj.resize(n);
        for (const auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
    }
    void bfs(size_t src, size_t n, const graph_t &edges) {
        vector<int> dist(n, -1);
        vector<size_t> parent(n, numeric_limits<size_t>::max());
        queue<size_t> q;
        q.push(src);
        dist[src] = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            for (const auto &v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    parent[v] = u;
                    q.push(v);
                } else if (parent[u] != v) ans = min(ans, dist[u] + dist[v] + 1);
            }
        }
    }
public:
    int findShortestCycle(size_t n, graph_t &edges) {
        if (edges.size() < n) return -1; // forests
        build_adj(n, edges);
        for (auto i = 0uz; i < n; i++) bfs(i, n, edges);
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};