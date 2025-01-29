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

// dsu template from https://github.com/wytsai7660
class dsu_t {
    vector<size_t> parent;
    vector<size_t> size;
public:
    explicit dsu_t(size_t n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }

    size_t find(size_t n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    } // path compression

    bool unite(size_t a, size_t b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // already connected
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    size_t size_of(size_t n) { return size[find(n)]; }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>> &edges) {
        const auto n = edges.size();
        dsu_t dsu(n);
        for (const auto &e : edges)
            if (!dsu.unite(e[0] - 1, e[1] - 1)) return e;
        return {};
    }
};

// class Solution {
//     vector<vector<int>> adj_graph;
//     vector<bool> visited;
//     vector<int> cycle;
//     bool found_cycle;
//     auto find(vector<int> &route, int target) {
//         for (auto begin = route.begin(); begin != route.end(); begin++) {
//             if (*begin == target) return begin;
//         }
//         return route.end();
//     }
//     void dfs(int node, int prev_node, vector<int> route) {
//         if (visited[node]) {
//             found_cycle = true;
//             cycle.assign(find(route, node), route.end());
//             return;
//         }
//         visited[node] = true;
//         route.push_back(node);
//         for (const auto &adj : adj_graph[node]) {
//             if (adj == prev_node) continue;
//             if (found_cycle) return;
//             dfs(adj, node, route);
//         }
//     }
// public:
//     vector<int> findRedundantConnection(vector<vector<int>> &edges) {
//         // build adjacent graph
//         adj_graph.resize(edges.size());
//         for (const auto &edge : edges) {
//             adj_graph[edge[0] - 1].push_back(edge[1] - 1);
//             adj_graph[edge[1] - 1].push_back(edge[0] - 1);
//         }

//         visited.resize(edges.size(), false);
//         found_cycle = false;
//         const int N = static_cast<int>(edges.size());
//         for (int i = 0; i < N; i++) {
//             if (found_cycle || visited[i]) continue;
//             vector<int> route;
//             dfs(i, -1, route);
//         }

//         for (auto &node : cycle)
//             node += 1;
//         cycle.push_back(cycle[0]);
//         for (int edge = N - 1; edge >= 0; edge--) {
//             for (int i = 1; i < static_cast<int>(cycle.size()); i++) {
//                 if (edges[edge][0] == cycle[i - 1] && edges[edge][1] == cycle[i] ||
//                 edges[edge][0] == cycle[i] && edges[edge][1] == cycle[i - 1])
//                     return edges[edge];
//             }
//         }
//         return {};
//     }
// };