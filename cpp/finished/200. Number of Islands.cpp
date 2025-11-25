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

class DisjointUnionSets {
    vector<int> size, parent;
    int num_unit;
public:
    DisjointUnionSets(int n) {
        size.resize(n, 1);
        parent.resize(n);
        this->num_unit = n;
        initSet();
    }
    void initSet() {
        for (int i = 0; i < num_unit; i++) {
            parent[i] = i;
        }
    }
    int findParent(int node) {
        if (parent[node] != node) parent[node] = findParent(parent[node]);
        return parent[node];
    }
    void mergeSet(int node_x, int node_y) {
        int parent_x = findParent(node_x), parent_y = findParent(node_y);
        if (parent_x == parent_y) return;
        if (size[parent_x] < size[parent_y]) swap(parent_x, parent_y);
        parent[parent_y] = parent_x, size[parent_x] += size[parent_y];
    }
    const bool isParent(int node) {
        return parent[node] == node;
    }
};

int countIslands(vector<vector<char>> &grid) {
    const int M = static_cast<int>(grid.size());
    const int N = static_cast<int>(grid[0].size());

    DisjointUnionSets *islands = new DisjointUnionSets(N * M);

    array<int, 5> mawari{0, 1, 0, -1, 0};
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '0') continue;

            for (int at = 0; at <= 3; at++) {
                if (i + mawari[at] < 0 || i + mawari[at] >= M) continue;
                if (j + mawari[at + 1] < 0 || j + mawari[at + 1] >= N) continue;
                if (grid[i + mawari[at]][j + mawari[at + 1]] == '0') continue;
                islands->mergeSet(i * N + j, (i + mawari[at]) * N + (j + mawari[at + 1]));
            }
        }
    }

    int num_island = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (grid[i][j] == '0') continue;
            if (islands->isParent(i * N + j)) num_island++;
        }
    }
    return num_island;
}

class Solution {
public:
    int numIslands(vector<vector<char>> &grid) {
        return countIslands(grid);
    }
};