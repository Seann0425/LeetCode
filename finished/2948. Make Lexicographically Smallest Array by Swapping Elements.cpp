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
    size_t m, n;
    auto dfs(vector<vector<int>> &grid, size_t i, size_t j) -> int {
        if (!grid[i][j]) return 0;
        auto size = grid[i][j];
        grid[i][j] = 0;
        if (i) size += dfs(grid, i - 1, j);
        if (j) size += dfs(grid, i, j - 1);
        if (i < m - 1) size += dfs(grid, i + 1, j);
        if (j < n - 1) size += dfs(grid, i, j + 1);
        return size;
    }
public:
    int findMaxFish(vector<vector<int>> &grid) {
        m = grid.size(), n = grid[0].size();
        auto ans = 0;
        for (auto i = 0uz; i < m; i++)
            for (auto j = 0uz; j < n; j++) ans = max(ans, dfs(grid, i, j));
        return ans;
    }
};

// ------------------------------------------------------ //

class dsu_t {
    vector<size_t> parent;
    vector<size_t> size;
public:
    explicit dsu_t(size_t n, vector<vector<int>> &graph) : parent(n), size(n) {
        iota(parent.begin(), parent.end(), 0);
        auto m = graph[0].size();
        for (auto i = 0uz; i < n; i++) {
            auto x = i / m, y = i % m;
            size[i] = graph[x][y] ? 1 : 0;
        }
    }

    size_t find(size_t n) {
        return parent[n] == n ? n : parent[n] = find(parent[n]);
    } // path compression

    bool unite(size_t a, size_t b) {
        a = find(a);
        b = find(b);
        if (a == b) return false; // already connected
        if (size[a] < size[b]) swap(a, b);
        parent[b] = a;
        size[a] += size[b];
        return true;
    }

    size_t size_of(size_t n) { return size[find(n)]; }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>> &grid) {
        const auto m = grid.size(), n = grid[0].size();
        dsu_t dsu(m * n, grid);
        auto ans = 0;
        for (auto i = 0uz; i < m; i++) {
            for (auto j = 0uz; j < n; j++) {
                if (!grid[i][j]) continue;
                if (i && grid[i - 1][j]) dsu.unite(i * n + j, (i - 1) * n + j);
                if (j && grid[i][j - 1]) dsu.unite(i * n + j, i * n + j - 1);
            }
        }
        unordered_map<int, int> fish;
        for (auto i = 0uz; i < m; i++) {
            for (auto j = 0uz; j < n; j++) {
                if (!grid[i][j]) continue;
                ans = max(ans, fish[dsu.find(i * n + j)] += grid[i][j]);
            }
        }
        return ans;
    }
};