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
    bool existCycle;
    void DFS(int node, const vector<vector<int>> &neighbors, vector<bool> &visited, vector<bool> &finished) {
        if (finished[node]) return;
        if (visited[node]) {
            existCycle = true;
            return;
        }
        visited[node] = true;
        for (const auto &n : neighbors[node]) {
            if (existCycle) return;
            DFS(n, neighbors, visited, finished);
        }
        finished[node] = true;
        return;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>> &prerequisites) {
        // examine if there's any cycle in a directed graph
        vector<vector<int>> neighbors(numCourses); // node, neighbors
        for (const auto &v : prerequisites)
            neighbors[v[1]].emplace_back(v[0]);

        vector<bool> visited(numCourses, false), finished(numCourses, false);
        existCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (existCycle) break;
            DFS(i, neighbors, visited, finished);
        }

        return !existCycle;
    }
};