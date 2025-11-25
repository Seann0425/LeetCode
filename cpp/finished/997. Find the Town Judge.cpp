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
    int findJudge(int n, vector<vector<int>> &trust) {
        vector<bool> row(n, 0);
        vector<vector<bool>> graph(n, row);
        for (auto &v : trust)
            graph[v[0] - 1][v[1] - 1] = 1;
        for (int i = 0; i < n; i++) {
            bool c = 1;
            for (int k = 0; k < n; k++) {
                if (graph[i][k] == 1) {
                    c = 0;
                    break;
                }
            }
            if (c) {
                bool C = 1;
                for (int j = 0; j < n; j++) {
                    if (!graph[j][i] and j != i) {
                        C = 0;
                        break;
                    }
                }
                if (C) return i + 1;
            }
        }
        return -1;
    }
};