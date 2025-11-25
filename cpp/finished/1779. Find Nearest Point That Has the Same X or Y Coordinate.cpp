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
    int isValid(int x, int y, vector<int> &v) {
        if (x != v[0] && y != v[1]) return -1;
        else return abs(v[0] - x) + abs(v[1] - y);
    }
public:
    int nearestValidPoint(int x, int y, vector<vector<int>> &points) {
        int idx = -1;
        int minimum = INT_MAX;
        for (int i = 0; i < points.size(); i++) {
            int distance = isValid(x, y, points[i]);
            if (distance >= 0 && distance < minimum) {
                minimum = distance;
                idx = i;
            }
        }
        return idx;
    }
};