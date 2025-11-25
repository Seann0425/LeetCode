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
    typedef pair<int, int> Coordinate;
public:
    int orangesRotting(vector<vector<int>> &grid) {
        /*
        0 => empty
        1 => fresh
        2 => rotten
        */
        const int M = grid.size();
        const int N = grid[0].size();
        int fresh_count = 0;
        queue<Coordinate> rotten1, rotten2;
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < N; j++) {
                if (grid[i][j] == 1) fresh_count++;
                else if (grid[i][j] == 2) rotten1.emplace(i, j);
            }
        }

        const array<int, 5> mawari{0, 1, 0, -1, 0};
        int ans = 0;
        while (fresh_count > 0 || (!rotten1.empty() && !rotten2.empty())) {
            while (!rotten1.empty()) {
                auto [x, y] = rotten1.front();
                rotten1.pop();
                for (int at = 0; at < 4; at++) {
                    int X = x + mawari[at], Y = y + mawari[at + 1];
                    if (X < 0 || Y < 0 || X >= M || Y >= N) continue;
                    if (grid[X][Y] == 1) {
                        grid[X][Y] = 2;
                        fresh_count--;
                        rotten2.emplace(X, Y);
                    }
                }
            }
            if (rotten2.empty()) break;
            ans++;
            while (!rotten2.empty()) {
                auto [x, y] = rotten2.front();
                rotten2.pop();
                for (int at = 0; at < 4; at++) {
                    int X = x + mawari[at], Y = y + mawari[at + 1];
                    if (X < 0 || Y < 0 || X >= M || Y >= N) continue;
                    if (grid[X][Y] == 1) {
                        grid[X][Y] = 2;
                        fresh_count--;
                        rotten1.emplace(X, Y);
                    }
                }
            }
            if (rotten1.empty()) break;
            ans++;
        }
        return fresh_count == 0 ? ans : -1;
    }
};