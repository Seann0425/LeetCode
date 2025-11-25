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
    const int INF = 1e6;
    void init(vector<vector<int>> &graph, const vector<vector<int>> &times, int n) {
        for (int i = 0; i < n; i++)
            graph[i][i] = 0; // the distance to the node itself should be 0
        for (auto v : times)
            graph[v[0] - 1][v[1] - 1] = v[2]; // store the information from times into graph
        return;
    }
public:
    int networkDelayTime(vector<vector<int>> &times, int n, int k) {
        // build a graph recording the direct distance between each node
        vector<vector<int>> graph(n, vector<int>(n, INF));

        // initialize the graph according to "times"
        init(graph, times, n);

        // the container for storaging the shortest distance from src node
        vector<int> dist(n, INF);
        dist[k - 1] = 0;
        unordered_set<int> unvisitedNodes;
        for (int i = 0; i < n; i++)
            unvisitedNodes.insert(i);

        while (!unvisitedNodes.empty()) {
            // find the nearest node that is not visited yet
            int nearestDistance = INT_MAX, nearest;
            for (auto itr : unvisitedNodes)
                if (dist[itr] < nearestDistance) {
                    nearestDistance = dist[itr];
                    nearest = itr;
                }

            unvisitedNodes.erase(nearest);

            for (int i = 0; i < n; i++)
                dist[i] = min(dist[i], dist[nearest] + graph[nearest][i]);
        }

        int maximum = *max_element(dist.begin(), dist.end());

        return (maximum == INF) ? -1 : maximum;
    }
};