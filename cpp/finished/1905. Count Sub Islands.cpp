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

class dsu_t {
public:
    vector<int> parent;
    vector<int> size;
    explicit dsu_t(size_t n) : parent(n), size(n, 1) { iota(parent.begin(), parent.end(), 0); }
    auto find_parent(int u) -> int {
        if (parent[u] == u) return u;
        return parent[u] = find_parent(parent[u]);
    }
    auto unite(int u, int v) -> void {
        auto pu = find_parent(u), pv = find_parent(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
    size_t m, n;
    using graph_t = vector<vector<int>>;
    auto dfs(size_t i, size_t j, graph_t &islands, graph_t &sub_islands, dsu_t &dsu,
             int belong) -> bool {
        if (i >= m || j >= n || !sub_islands[i][j]) return true;
        auto illegal = !islands[i][j] && sub_islands[i][j];
        sub_islands[i][j] = 0;
        auto up = dfs(i - 1, j, islands, sub_islands, dsu, belong);
        auto left = dfs(i, j - 1, islands, sub_islands, dsu, belong);
        auto down = dfs(i + 1, j, islands, sub_islands, dsu, belong);
        auto right = dfs(i, j + 1, islands, sub_islands, dsu, belong);
        if (dsu.find_parent(i * n + j) != belong or illegal) return false;
        return up && left && down && right;
    }
public:
    int countSubIslands(graph_t &islands, graph_t &sub_islands) {
        m = islands.size();
        n = islands[0].size();
        dsu_t dsu(m * n);
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (!islands[i][j]) continue;
                if (i && islands[i - 1][j]) dsu.unite(i * n + j, (i - 1) * n + j);
                if (j && islands[i][j - 1]) dsu.unite(i * n + j, i * n + j - 1);
            }
        }
        auto ans = 0;
        for (size_t i = 0; i < m; i++) {
            for (size_t j = 0; j < n; j++) {
                if (!sub_islands[i][j]) continue;
                auto belong = dsu.find_parent(i * n + j);
                ans += dfs(i, j, islands, sub_islands, dsu, belong);
            }
        }
        return ans;
    }
};
