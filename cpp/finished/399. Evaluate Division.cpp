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
    // to record the division relationship that are already known
    unordered_map<string, unordered_map<string, double>> division;

    // a recursive func. to visit possible path
    double findDistance(string src, string dest, unordered_set<string> &visited) {
        if (division[src].count(dest)) return division[src][dest];

        for (auto node : division[src]) {
            if (visited.count(node.first)) continue;
            visited.insert(node.first);
            double distance = findDistance(node.first, dest, visited);
            if (distance > 0.0) return distance * division[src][node.first];
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // get the known information
        for (int i = 0; i < equations.size(); i++) {
            division[equations[i][0]][equations[i][1]] = values[i];
            division[equations[i][1]][equations[i][0]] = 1.0 / values[i];
        }

        // loop over the queries and store the answer in the vector with the help of the recursive func.
        vector<double> res(queries.size());
        for (int i = 0; i < queries.size(); i++) {
            unordered_set<string> visited;
            double distance = findDistance(queries[i][0], queries[i][1], visited);
            res[i] = (distance > 0) ? distance : -1;
        }
        return res;
    }
};