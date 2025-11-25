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
    static constexpr array<int, 5> direction{-1, 0, 1, 0, -1};
    auto dfs_mark(vector<vector<char>> &board, size_t i, size_t j) {
        if (i >= m or j >= n or board[i][j] != 'O') return;
        board[i][j] = 'M';
        for (auto k = 0uz; k < 4uz; k++) dfs_mark(board, i + direction[k], j + direction[k + 1]);
    }
    auto capture(vector<vector<char>> &board) {
        for (auto i = 0uz; i < m; i++)
            for (auto j = 0uz; j < n; j++)
                if (board[i][j] == 'M') board[i][j] = 'O';
                else if (board[i][j] == 'O') board[i][j] = 'X';
    }
public:
    void solve(vector<vector<char>> &board) {
        m = board.size(), n = board[0].size();
        for (auto i = 0uz; i < n; i++) {
            if (board[0][i] == 'O') dfs_mark(board, 0, i);
            if (board[m - 1][i] == 'O') dfs_mark(board, m - 1, i);
        }
        for (auto i = 0uz; i < m; i++) {
            if (board[i][0] == 'O') dfs_mark(board, i, 0);
            if (board[i][n - 1] == 'O') dfs_mark(board, i, n - 1);
        }
        capture(board);
    }
};