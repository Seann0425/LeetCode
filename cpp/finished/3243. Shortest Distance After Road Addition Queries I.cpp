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
    vector<vector<size_t>> graph;
    int bfs(size_t u, size_t v) {
        graph[u].push_back(v);

        const auto n = graph.size();
        vector<bool> visited(n, false);
        queue<size_t> q;
        q.push(0uz);
        visited[0] = true;
        auto ans = 0;
        while (!q.empty()) {
            ans++;
            for (size_t i = q.size(); i > 0; i--) {
                const auto x = q.front();
                q.pop();
                for (const auto y : graph[x]) {
                    if (visited[y]) continue;
                    if (y == n - 1) return ans;
                    visited[y] = true;
                    q.push(y);
                }
            }
        }
        return -1;
    }
public:
    vector<int> shortestDistanceAfterQueries(size_t n, vector<vector<int>> &queries) {
        graph.resize(n);
        for (size_t i = 0; i < n - 1; i++) graph[i].push_back(i + 1);

        const auto m = queries.size();
        vector<int> ans;
        ans.reserve(m);
        for (const auto &q : queries) ans.push_back(bfs(q[0], q[1]));
        return ans;
    }
};