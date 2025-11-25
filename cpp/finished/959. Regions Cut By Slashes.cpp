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
    void dfs(vector<vector<bool>> &visited, size_t i, size_t j) {
        if (i >= n or j >= n or visited[i][j]) return;
        visited[i][j] = true;
        dfs(visited, i + 1, j);
        dfs(visited, i - 1, j);
        dfs(visited, i, j + 1);
        dfs(visited, i, j - 1);
    }
public:
    int regionsBySlashes(vector<string> &grid) {
        const auto origin_n = grid.size();
        n = origin_n * 3;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        for (size_t i = 0; i < origin_n; i++) {
            for (size_t j = 0; j < origin_n; j++) {
                if (grid[i][j] == '/') {
                    visited[i * 3][j * 3 + 2] = true;
                    visited[i * 3 + 1][j * 3 + 1] = true;
                    visited[i * 3 + 2][j * 3] = true;
                } else if (grid[i][j] == '\\') {
                    visited[i * 3][j * 3] = true;
                    visited[i * 3 + 1][j * 3 + 1] = true;
                    visited[i * 3 + 2][j * 3 + 2] = true;
                }
            }
        }
        auto ans = 0;
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    dfs(visited, i, j);
                    ans++;
                }
            }
        }
        return ans;
    }
};