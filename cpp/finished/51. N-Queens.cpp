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
    vector<string> board;
    vector<vector<string>> ans;
    bool check_queen(size_t x, size_t y) {
        // up
        for (size_t i = 0; i < x; i++)
            if (board[i][y] == 'Q') return false;
        // left up
        for (size_t i = x - 1; i < n && y - x + i < n; i--)
            if (board[i][y - x + i] == 'Q') return false;
        // right up
        for (size_t i = x - 1; i < n && y + x - i < n; i--)
            if (board[i][y + x - i] == 'Q') return false;
        return true;
    }
    void kth_queen(size_t row) {
        if (row == n) {
            ans.push_back(board);
            return;
        }
        for (size_t i = 0; i < n; i++) {
            if (check_queen(row, i)) {
                board[row][i] = 'Q';
                kth_queen(row + 1);
                board[row][i] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int input_n) {
        n = static_cast<size_t>(input_n);
        board.resize(n, string(n, '.'));
        kth_queen(0uz);
        return ans;
    }
};