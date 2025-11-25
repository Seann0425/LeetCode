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
    void neighborCheck(int i, int j, vector<vector<int>> &dist) {
        if (dist[i][j] == 0 || dist[i][j] == 1) return;
        bool changed = false;
        for (int k = -1; k <= 1; k++) {
            for (int l = -1; l <= 1; l++) {
                if (abs(k) + abs(l) != 1 || i + k < 0 || i + k >= dist.size() || j + l < 0 || j + l >= dist[0].size()) continue; // check only
                                                                                                                                 // adjacent
                if (dist[i + k][j + l] + 1 < dist[i][j]) {
                    changed = true;
                    dist[i][j] = dist[i + k][j + l] + 1;
                }
            }
        }

        if (changed) {
            for (int k = -1; k <= 1; k++) {
                for (int l = -1; l <= 1; l++) {
                    if (abs(k) + abs(l) != 1 || i + k < 0 || i + k >= dist.size() || j + l < 0 || j + l >= dist[0].size()) continue;
                    neighborCheck(i + k, j + l, dist);
                }
            }
        }
        return;
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        const int M = mat.size();
        const int N = mat[0].size();
        const int INF = 1e5;
        vector<vector<int>> dist(M, vector<int>(N, INF));
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++)
                if (mat[i][j] == 0) dist[i][j] = 0;
        }

        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (dist[i][j] != 0) neighborCheck(i, j, dist);
            }
        }

        return dist;
    }
};