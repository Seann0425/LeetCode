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
    using board_t = vector<vector<char>>;
    constexpr static array<int, 9> dirs{-1, -1, 0, -1, 1, 0, 1, 1, -1};
    size_t m, n;
    void dfs(board_t &board, size_t x, size_t y) {
        auto cnt = 0;
        for (auto i = 0uz; i < 8uz; i++) {
            auto nx = x + dirs[i], ny = y + dirs[i + 1];
            if (nx >= m or ny >= n) continue;
            cnt += board[nx][ny] == 'M';
        }
        if (cnt) board[x][y] = cnt + '0';
        else {
            board[x][y] = 'B';
            for (auto i = 0uz; i < 8uz; i++) {
                auto nx = x + dirs[i], ny = y + dirs[i + 1];
                if (nx >= m or ny >= n or board[nx][ny] != 'E') continue;
                dfs(board, nx, ny);
            }
        }
    }
public:
    board_t updateBoard(board_t &board, vector<int> &click) {
        m = board.size(), n = board[0].size();
        auto [x, y] = tie(click[0], click[1]);
        if (board[x][y] == 'M') return board[x][y] = 'X', board;
        dfs(board, x, y);
        return board;
    }
};