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
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

// inspired by PinkNekoFist
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        const auto row = static_cast<size_t>(m), col = static_cast<size_t>(n);
        vector<vector<int>> mat(row, vector<int>(col, -1));
        array<int, 5> direct{0, 1, 0, -1, 0};
        size_t i = 0, j = 0, face = 0;

        while (head) {
            mat[i][j] = head->val;
            head = head->next;

            auto new_i = i + direct[face], new_j = j + direct[face + 1];
            if (new_i >= row or new_j >= col or mat[new_i][new_j] != -1) ++face %= 4;
            i += direct[face];
            j += direct[face + 1];
        }

        return mat;
    }
};