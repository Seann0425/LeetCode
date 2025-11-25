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
    const array<int, 5> direc{0, 1, 0, -1, 0};
public:
    vector<vector<int>> spiralMatrixIII(size_t rows, size_t cols, int row_start, int col_start) {
        const auto n = rows * cols;
        vector<vector<int>> ans{{row_start, col_start}};
        ans.reserve(n);
        auto new_phase = false;
        auto facing = 0uz;
        for (auto step = 0, phase = 1; ans.size() < n; step++) {
            if (step == phase) {
                step = 0;
                new_phase = new_phase ? (phase++, false) : true;
                facing = (facing + 1) % 4;
            }
            row_start += direc[facing];
            col_start += direc[facing + 1];
            if (row_start < 0 or row_start >= rows or col_start < 0 or col_start >= cols) continue;
            ans.push_back({row_start, col_start});
        }
        return ans;
    }
};