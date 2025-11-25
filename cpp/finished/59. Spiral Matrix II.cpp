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
    const int NOT_VISITED = 0;
    const array<int, 5> direc{0, 1, 0, -1, 0};
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n, NOT_VISITED));
        const auto sqr_n = n * n;
        auto x = 0uz, y = 0uz, facing = 0uz;
        for (auto i = 1; i <= sqr_n; i++) {
            matrix[x][y] = i;
            const auto new_x = x + direc[facing], new_y = y + direc[facing + 1];
            if (new_x >= n or new_y >= n or matrix[new_x][new_y] != NOT_VISITED)
                facing = (facing + 1) % 4;
            x += direc[facing];
            y += direc[facing + 1];
        }
        return matrix;
    }
};