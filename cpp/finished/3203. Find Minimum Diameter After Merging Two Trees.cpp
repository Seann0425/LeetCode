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
    int minimumDiameterAfterMerge(vector<vector<int>> &edges1, vector<vector<int>> &edges2) {
        const auto n = edges1.size() + 1, m = edges2.size() + 1;
        vector<vector<int>> adj_list1, adj_list2;
        build_adj_list(edges1, n, adj_list1);
        build_adj_list(edges2, m, adj_list2);

        auto diameter1 = get_diameter(adj_list1, n);
        auto diameter2 = get_diameter(adj_list2, m);
        auto merged_diameter = (diameter1 + 1) / 2 + (diameter2 + 1) / 2 + 1;

        return max({diameter1, diameter2, merged_diameter});
    }
private:
    void build_adj_list(const vector<vector<int>> &edges, size_t n, vector<vector<int>> &adj_list) {
        adj_list.resize(n);
        for (const auto &edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
    }
    int get_diameter(const vector<vector<int>> &adj_list, size_t n) {
        auto [farthest_node, _] = bfs(adj_list, n, 0);
        auto [_, diameter] = bfs(adj_list, n, farthest_node);
        return diameter;
    }

    pair<size_t, int> bfs(const vector<vector<int>> &adj_list, size_t n, size_t src) {
        queue<size_t> q;
        vector<bool> visited(n);
        q.push(src);
        visited[src] = true;
        auto max_dist = 0;
        auto farthest = src;
        while (!q.empty()) {
            auto size = q.size();
            for (auto i = 0uz; i < size; i++) {
                auto u = q.front();
                q.pop();
                farthest = u;
                for (const auto &v : adj_list[u]) {
                    if (!visited[v]) {
                        visited[v] = true;
                        q.push(v);
                    }
                }
            }
            if (!q.empty()) max_dist++;
        }
        return {farthest, max_dist};
    }
};