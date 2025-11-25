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
private:
    bool existCycle;
    void init(vector<vector<int>> &graph, vector<vector<int>> &pre) {
        for (const auto &v : pre)
            graph[v[1]].push_back(v[0]);
        return;
    }

    void dfs(int at, vector<bool> &visited, vector<int> &route, const vector<vector<int>> &graph) {
        visited[at] = true;

        for (int node : graph[at]) {
            if (visited[node] == true) continue;

            dfs(node, visited, route, graph);
        }
        route.push_back(at);
        return;
    }

    void checkCycle(int node, const vector<vector<int>> &neighbors, vector<bool> &visited, vector<bool> &finished) {
        if (finished[node]) return;
        if (visited[node]) {
            existCycle = true;
            return;
        }
        visited[node] = true;
        for (const auto &n : neighbors[node]) {
            if (existCycle) return;
            checkCycle(n, neighbors, visited, finished);
        }
        finished[node] = true;
        return;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites) {
        // build a graph that record the adjacent nodes
        vector<vector<int>> graph(numCourses);
        init(graph, prerequisites);

        vector<bool> visit(numCourses, false), finished(numCourses, false);
        existCycle = false;
        for (int i = 0; i < numCourses; i++) {
            if (existCycle) return {};
            checkCycle(i, graph, visit, finished);
        }

        vector<bool> visited(numCourses, false);
        vector<int> res(numCourses);
        int idx = numCourses - 1;

        for (int at = 0; at < numCourses; at++) {
            if (visited[at] == true) continue;

            vector<int> route;
            dfs(at, visited, route, graph);
            for (int &nodeId : route)
                res[idx--] = nodeId;
        }

        return res;
    }
};