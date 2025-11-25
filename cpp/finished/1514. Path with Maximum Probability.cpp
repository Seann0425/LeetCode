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
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

// dijkstra
class Solution {
    typedef pair<double, size_t> Path;
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<double> probs(static_cast<size_t>(n), 0);
        vector<vector<Path>> adj(static_cast<size_t>(n));
        priority_queue<Path, vector<Path>, less<Path>> pq;

        const auto n_edge = edges.size();
        for (size_t i = 0; i < n_edge; i++) {
            adj[edges[i].front()].emplace_back(succProb[i], edges[i].back());
            adj[edges[i].back()].emplace_back(succProb[i], edges[i].front());
        }

        probs[start_node] = 1;
        pq.emplace(1.0, static_cast<size_t>(start_node));

        while (!pq.empty()) {
            auto u = pq.top().second;
            pq.pop();

            if (u == end_node) return probs[u];
            for (auto itr = adj[u].begin(); itr != adj[u].end(); itr++) {
                auto [prob, v] = *itr;

                if (probs[v] < probs[u] * prob) {
                    probs[v] = probs[u] * prob;
                    pq.emplace(probs[v], v);
                }
            }
        }

        return probs[end_node];
    }
};

// bellman-ford
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        const auto e = edges.size(), n_count = static_cast<size_t>(n);
        vector<double> probability(n_count, 0.0);
        probability[start_node] = 1.0;


        for (size_t i = 0; i < n_count - 1; i++) {
            auto updated = false;
            for (size_t j = 0; j < e; j++) {
                auto u = static_cast<size_t>(edges[j].front()), v = static_cast<size_t>(edges[j].back());
                auto w = succProb[j];
                if (probability[v] < probability[u] * w) {
                    probability[v] = probability[u] * w;
                    updated = true;
                }
                if (probability[u] < probability[v] * w) {
                    probability[u] = probability[v] * w;
                    updated = true;
                }
            }
            if (!updated) break;
        }

        return probability[end_node];
    }
};
