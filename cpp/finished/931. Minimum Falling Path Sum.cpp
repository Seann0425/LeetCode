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
    int minFallingPathSum(vector<vector<int>> &matrix) {
        if (matrix.size() == 1) return matrix[0][0];

        const int N = matrix.size();
        for (int row = 1; row < N; row++) {
            matrix[row][0] += min(matrix[row - 1][0], matrix[row - 1][1]);
            matrix[row][N - 1] += min(matrix[row - 1][N - 1], matrix[row - 1][N - 2]);
            for (int col = 1; col < N - 1; col++)
                matrix[row][col] += min(matrix[row - 1][col - 1], min(matrix[row - 1][col], matrix[row - 1][col + 1]));
        }

        return *min_element(matrix[N - 1].begin(), matrix[N - 1].end());
    }
};