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
    void find(size_t i, size_t j, const vector<vector<int>> &land, vector<int> &group) {
        if ((i == land.size() - 1 || land[i + 1][j] == 0) && (j == land[0].size() - 1 || land[i][j + 1] == 0)) {
            group.push_back(i);
            group.push_back(j);
            return;
        }
        if (i != land.size() - 1 && land[i + 1][j] != 0) find(i + 1, j, land, group);
        else find(i, j + 1, land, group);
    }
public:
    vector<vector<int>> findFarmland(vector<vector<int>> &land) {
        vector<vector<int>> groups;
        const auto M = land.size();
        const auto N = land[0].size();
        for (size_t i = 0; i < M; i++) {
            for (size_t j = 0; j < N; j++) {
                if (land[i][j] == 0) continue;
                if ((i == 0 || land[i - 1][j] == 0) && (j == 0 || land[i][j - 1] == 0)) {
                    int y, x;
                    y = static_cast<int>(i);
                    x = static_cast<int>(j);
                    groups.push_back({y, x});
                    find(i, j, land, groups.back());
                }
            }
        }
        return groups;
    }
};