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
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        const int sz = gas.size();
        vector<bool> attempted(sz);
        vector<int> exchange(sz);
        for (int i = 0; i < sz; i++) {
            exchange[i] = gas[i] - cost[i];
            attempted[i] = (exchange[i] < 0);
        }
        for (int i = 0; i < sz; i++) {
            if (attempted[i]) continue;
            vector<bool> visited(attempted.begin(), attempted.end());
            int ownedGas = exchange[i], idx = i;
            while (((++idx) % sz) != i) {
                ownedGas += exchange[idx % sz];
                if (ownedGas < 0) {
                    attempted = visited;
                    break;
                }
                visited[idx % sz] = true;
            }
            if (ownedGas >= 0) return i;
        }
        return -1;
    }
};