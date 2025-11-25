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
#define points P
public:
    bool isBoomerang(vector<vector<int>> &P) {
        int dx1 = P[1][0] - P[0][0];
        int dy1 = P[1][1] - P[0][1];
        int dx2 = P[2][0] - P[1][0];
        int dy2 = P[2][1] - P[1][1];
        if (dx1 == 0 && dy1 == 0 || dx2 == 0 && dy2 == 0 || P[0][0] == P[2][0] && P[0][1] == P[2][1]) return false;
        return dx1 * dy2 != dx2 * dy1;
    }
};