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
    int oddCells(int m, int n, vector<vector<int>> &indices) {
        vector<int> row(m, 0);
        vector<int> column(n, 0);
        for (auto v : indices) {
            row[v[0]]++;
            column[v[1]]++;
        }
        int odd = 0;
        int oddRow = 0;
        for (int i : row)
            if (i % 2) odd += n, oddRow++;
        for (int i : column)
            if (i % 2) odd = odd - oddRow + (m - oddRow);
        return odd;
    }
};