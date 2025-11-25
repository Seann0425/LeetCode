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
    int cherryPickup(vector<vector<int>> &grid) {
        // setup
        const int M = grid.size();
        const int N = grid[0].size();
        vector<vector<vector<int>>> DP(M, vector<vector<int>>(N, vector<int>(N, INT_MIN))); // negative => invalid
        DP[0][0][N - 1] = grid[0][0] + grid[0][N - 1];

        for (int row = 1; row < M; row++) {
            // robot A and B
            for (int A = 0; A < N; A++) {
                for (int B = 0; B < N; B++) {
                    if (A > row || B < N - 1 - row) continue;
                    vector<int> candidate;

                    for (int colA = -1; colA <= 1; colA++) {
                        for (int colB = -1; colB <= 1; colB++) {
                            if (A + colA >= 0 && A + colA <= N - 1 && B + colB >= 0 && B + colB <= N - 1) {
                                candidate.push_back(DP[row - 1][A + colA][B + colB] + grid[row][A] + ((A != B) ? (grid[row][B]) : 0));
                            }
                        }
                    }

                    DP[row][A][B] = *max_element(candidate.begin(), candidate.end());
                }
            }
        }

        int maximum = INT_MIN;
        for (auto &v : DP[M - 1])
            for (auto &i : v)
                maximum = max(maximum, i);

        return maximum;
    }
};