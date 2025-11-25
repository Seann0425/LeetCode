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
    int longestCommonSubsequence(string text1, string text2) {
        int m = text2.size(), n = text1.size();
        vector<int> row(n);
        vector<vector<int>> grid(m, row);

        // generate the first row of the grid
        for (int i = 0; i < n; i++) {
            if (text1[i] != text2[0]) grid[0][i] = 0;
            else
                while (i < n)
                    grid[0][i++] = 1;
        }
        // generate the first column of the grid
        for (int i = 0; i < m; i++) {
            if (text1[0] != text2[i]) grid[i][0] = 0;
            else
                while (i < m)
                    grid[i++][0] = 1;
        }
        // complete the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] = (text1[j] == text2[i]) ? (grid[i - 1][j - 1] + 1) : (max(grid[i - 1][j], grid[i][j - 1]));
            }
        }

        // return the last element
        return grid[m - 1][n - 1];
    }
};