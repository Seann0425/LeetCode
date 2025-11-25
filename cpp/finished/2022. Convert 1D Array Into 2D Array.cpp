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

class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
        auto row = static_cast<size_t>(m), col = static_cast<size_t>(n);
        if (row * col != original.size()) return {};
        vector<vector<int>> res(row, vector<int>(col));
        size_t k = 0;
        for (size_t i = 0; i < row; i++) {
            for (size_t j = 0; j < col; j++) {
                res[i][j] = original[k++];
            }
        }

        return res;
    }
};

// class Solution {
// public:
//     vector<vector<int>> construct2DArray(vector<int> &original, int m, int n) {
//         vector<vector<int>> res;
//         if (m * n != original.size()) return res;
//         int idx = 0;
//         res.resize(m, vector<int>(n));
//         for (int i = 0; i < m; i++) {
//             for (int j = 0; j < n; j++) {
//                 res[i][j] = original[idx++];
//             }
//         }
//         return res;
//     }
// };