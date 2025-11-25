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
    int areaOfMaxDiagonal(vector<vector<int>> &dimensions) {
        int idx = 0;
        double longest = 0;
        for (int i = 0; i < dimensions.size(); i++) {
            double cur = sqrt(pow(dimensions[i][0], 2) + pow(dimensions[i][1], 2));
            if (cur > longest) {
                longest = cur;
                idx = i;
            } else if (cur == longest && dimensions[i][0] * dimensions[i][1] > dimensions[idx][0] * dimensions[idx][1]) idx = i;
        }
        return dimensions[idx][0] * dimensions[idx][1];
    }
};