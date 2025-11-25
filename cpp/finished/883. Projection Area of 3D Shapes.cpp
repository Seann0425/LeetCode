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
    void xyANDxz(vector<int> &row, int &xy, int &xz) {
        int mx = 0;
        for (auto &t : row) {
            if (t > 0) xy++;
            mx = max(mx, t);
        }
        xz += mx;
        return;
    }

    void yzONLY(vector<vector<int>> &grid, int &yz, int column) {
        int mx = 0;
        for (int i = 0; i < grid.size(); i++)
            mx = max(mx, grid[i][column]);
        yz += mx;
        return;
    }
public:
    int projectionArea(vector<vector<int>> &grid) {
        // xy takes the amount of points that are not zero
        // xz takes the maximum in each row
        // yz takes the maximum in each column
        int xy = 0, xz = 0, yz = 0;
        for (int i = 0; i < grid.size(); i++)
            xyANDxz(grid[i], xy, xz);
        for (int i = 0; i < grid[0].size(); i++)
            yzONLY(grid, yz, i);
        return xy + xz + yz;
    }
};