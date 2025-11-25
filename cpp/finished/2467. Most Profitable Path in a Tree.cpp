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
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
    size_t n;
    vector<vector<int>> graph;
    vector<int> dist_bob;
    auto dfs(int node, int parent, int dist, int bob, const vector<int> &amount) -> int {
        auto max_profit = 0, max_child = numeric_limits<int>::min();
        if (node == bob) dist_bob[node] = 0;
        for (const auto &child : graph[node]) {
            if (child == parent) continue;
            max_child = max(max_child, dfs(child, node, dist + 1, bob, amount));
            dist_bob[node] = min(dist_bob[node], dist_bob[child] + 1);
        }
        if (dist_bob[node] > dist) max_profit += amount[node];
        else if (dist_bob[node] == dist) max_profit += amount[node] / 2;
        // check if the node is a leaf
        return max_child == numeric_limits<int>::min() ? max_profit : max_profit + max_child;
    }
public:
    int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount) {
        n = amount.size();
        graph.resize(n);
        dist_bob.resize(n, n);
        for (const auto &e : edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        return dfs(0, 0, 0, bob, amount);
    }
};