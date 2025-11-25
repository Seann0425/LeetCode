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
    bool diagonal(vector<vector<int>> &mat, int sr, int sc) {
        int r = sr, c = sc;
        while (r < mat.size() && c < mat[0].size()) {
            if (mat[r][c] == mat[sr][sc]) r++, c++;
            else return false;
        }
        return true;
    }

    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        ios_base::sync_with_stdio(0);
        if (matrix.size() == 1) return true;
        for (int i = 0; i < matrix[0].size(); i++)
            if (!diagonal(matrix, 0, i)) return false;
        for (int i = 1; i < matrix.size(); i++)
            if (!diagonal(matrix, i, 0)) return false;
        return true;
    }
};