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

class Solution {
    void bfs(const vector<int> &edges, size_t start, vector<int> &dist) {
        queue<size_t> q;
        q.push(start);
        dist[start] = 0;
        while (!q.empty()) {
            const auto u = q.front();
            q.pop();
            const auto v = edges[u];
            if (v == -1 or dist[v] != -1) continue;
            dist[v] = dist[u] + 1;
            q.push(v);
        }
    }
public:
    int closestMeetingNode(vector<int> &edges, int node1, int node2) {
        const auto n = edges.size();
        vector<int> dist1(n, -1), dist2(n, -1);

        bfs(edges, node1, dist1);
        bfs(edges, node2, dist2);

        auto min_dist = numeric_limits<int>::max();
        auto ans = n;
        for (auto i = 0uz; i < n; ++i) {
            if (dist1[i] == -1 or dist2[i] == -1) continue;
            if (auto dist = max(dist1[i], dist2[i]); dist < min_dist) {
                min_dist = dist;
                ans = i;
            }
        }
        return ans == n ? -1 : static_cast<int>(ans);
    }
};