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
    size_t n;
    vector<bool> finished;
    vector<bool> visited;
    vector<bool> in_cycle;
    // return in cycle
    bool dfs(const vector<vector<int>> &graph, size_t node) {
        if (finished[node]) return in_cycle[node];
        if (visited[node]) return in_cycle[node] = true;
        visited[node] = true;
        for (const auto &i : graph[node])
            if (dfs(graph, i)) in_cycle[node] = true;
        finished[node] = true;
        return in_cycle[node];
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>> &graph) {
        n = graph.size();
        finished.resize(n);
        visited.resize(n);
        in_cycle.resize(n);
        vector<int> ans;
        for (auto i = 0uz; i < n; i++) dfs(graph, i);
        for (auto i = 0uz; i < n; i++)
            if (!in_cycle[i]) ans.push_back(i);
        return ans;
    }
};