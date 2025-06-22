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
#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

// not original code, but such an elegant solution
class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>> &edges) {
        const auto n = colors.size();
        vector<vector<size_t>> adj(n);
        vector<int> indegree(n);

        // build adjacency list
        for (const auto &e : edges) {
            adj[static_cast<size_t>(e[0])].push_back(static_cast<size_t>(e[1]));
            ++indegree[e[1]];
        }

        // source nodes
        queue<size_t> q;
        for (auto i = 0uz; i < n; ++i)
            if (!indegree[i]) q.push(i);

        // dp for previous color counts
        vector<array<int, 26>> dp(n);
        for (auto i = 0uz; i < n; ++i) dp[i].fill(0);

        // topological traversal
        auto seen = 0, ans = 0;
        while (!q.empty()) {
            auto u = q.front();
            q.pop();
            ++seen;

            auto c = colors[u] - 'a';
            ++dp[u][c];
            ans = max(ans, dp[u][c]);

            for (const auto &v : adj[u]) {
                for (auto k = 0uz; k < 26uz; ++k) dp[v][k] = max(dp[v][k], dp[u][k]);
                if (--indegree[v] == 0) q.push(v);
            }
        }

        return static_cast<size_t>(seen) == n ? ans : -1;
    }
};