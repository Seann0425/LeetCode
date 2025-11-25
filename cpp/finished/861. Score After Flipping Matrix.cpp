#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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
// static const auto __ = []() {
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
    inline void flip(vector<int> &grid) {
        for (auto &x : grid)
            x ^= 1;
    }
public:
    int matrixScore(vector<vector<int>> &grid) {
        auto M = grid.size();
        auto N = grid.front().size();

        // first column check
        size_t cntr = 0;
        for (size_t i = 0; i < M; i++) {
            if (grid[i][0]) cntr++;
        }
        if (cntr > M - cntr) {
            for (size_t i = 0; i < M; i++) {
                grid[i][0] = 1 - grid[i][0];
            }
        }

        for (size_t i = 0; i < M; i++) {
            if (!grid[i][0]) flip(grid[i]);
        }

        int ans = 0;
        for (size_t j = 0; j < N; j++) {
            int numOf1 = 0;
            for (size_t i = 0; i < M; i++) {
                numOf1 += grid[i][j];
            }
            ans <<= 1;
            ans += max(numOf1, static_cast<int>(M) - numOf1);
        }
        return ans;
    }
};