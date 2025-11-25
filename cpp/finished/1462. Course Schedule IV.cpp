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

// inspired by wytsai7660@github
class Solution {
    static constexpr size_t max_n = 105;
public:
    vector<bool> checkIfPrerequisite(size_t n, vector<vector<int>> &edges,
                                     vector<vector<int>> &queries) {
        vector<bitset<max_n>> reach(n);
        vector<vector<size_t>> adj(n);
        vector<int> in_degree(n);
        for (const auto &e : edges) adj[e[0]].push_back(e[1]), in_degree[e[1]]++;
        queue<size_t> bfs;
        for (auto i = 0uz; i < n; i++) {
            if (!in_degree[i]) bfs.push(i);
            reach[i].set(i);
        }
        while (!bfs.empty()) {
            auto u = bfs.front();
            bfs.pop();
            for (const auto &v : adj[u]) {
                reach[v] |= reach[u];
                if (!(--in_degree[v])) bfs.push(v);
            }
        }
        vector<bool> ans;
        ans.reserve(queries.size());
        for (const auto &q : queries) ans.push_back(reach[q[1]][q[0]]);
        return ans;
    }
};