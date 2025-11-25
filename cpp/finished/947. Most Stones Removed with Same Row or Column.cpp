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
    auto find(int node) -> int {
        if (parent[node] == node) return node;
        return parent[node] = find(parent[node]);
    }
    auto unite(int u, int v) -> void {
        auto pu = find(u), pv = find(v);
        if (pu == pv) return;
        if (size[pu] < size[pv]) swap(pu, pv);
        parent[pv] = pu;
        size[pu] += size[pv];
    }
};

class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        auto n = stones.size();
        auto max_row = max_element(stones.begin(), stones.end())->at(0);
        auto max_col =
            max_element(stones.begin(), stones.end(), [](const auto &lhs, const auto &rhs) {
                return lhs[1] < rhs[1];
            })->at(1);
        const auto line_size = static_cast<size_t>(max_row + max_col + 2);
        dsu_t dsu(line_size);
        for (const auto &stone : stones) {
            auto row = stone[0], col = stone[1] + max_row + 1;
            dsu.unite(row, col);
        }
        for (size_t i = 0; i < line_size; i++)
            if (dsu.parent[i] == i && dsu.size[i] > 1) n--;
        return n;
    }
};