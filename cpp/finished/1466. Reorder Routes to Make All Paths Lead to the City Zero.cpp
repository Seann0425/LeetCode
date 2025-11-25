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
    using Graph = vector<vector<pair<int, bool>>>; // {v, direc}
    Graph undirected;
    vector<bool> visited;
    int ans = 0;
    void dfs(size_t u) {
        visited[u] = true;
        for (const auto &[v, direc] : undirected[u]) {
            if (visited[v]) continue;
            ans += direc;
            dfs(v);
        }
    }
public:
    int minReorder(size_t n, vector<vector<int>> &connections) {
        undirected.resize(n);
        for (const auto &con : connections) {
            auto u = con[0], v = con[1];
            undirected[u].emplace_back(v, true);
            undirected[v].emplace_back(u, false);
        }

        visited.resize(n, false);
        dfs(0);
        return ans;
    }
};