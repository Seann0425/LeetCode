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
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
        queue<vector<int>> points;
        vector<int> R(cols, 0);
        vector<vector<int>> G(rows, R);
        vector<vector<int>> ans;
        points.push({rCenter, cCenter});
        G[rCenter][cCenter] = 1;
        while (!points.empty()) {
            ans.push_back(points.front());
            int r = points.front()[0];
            int c = points.front()[1];
            points.pop();
            if (r > 0 && !G[r - 1][c]) {
                points.push({r - 1, c});
                G[r - 1][c] = 1;
            }
            if (r < rows - 1 && !G[r + 1][c]) {
                points.push({r + 1, c});
                G[r + 1][c] = 1;
            }
            if (c > 0 && !G[r][c - 1]) {
                points.push({r, c - 1});
                G[r][c - 1] = 1;
            }
            if (c < cols - 1 && !G[r][c + 1]) {
                points.push({r, c + 1});
                G[r][c + 1] = 1;
            }
        }
        return ans;
    }
};