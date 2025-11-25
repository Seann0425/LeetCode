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
    int hardestWorker(int n, vector<vector<int>> &logs) {
        vector<int> workTime(logs.size());
        int prev = 0;
        for (int i = 0; i < logs.size(); i++) {
            workTime[i] = logs[i][1] - prev;
            prev = logs[i][1];
        }
        int longest = 0;
        vector<int> candidate({logs[0][0]});
        for (int i = 0; i < logs.size(); i++) {
            if (workTime[i] == workTime[longest]) candidate.push_back(logs[i][0]);
            else if (workTime[i] > workTime[longest]) {
                longest = i;
                candidate.clear();
                candidate.push_back(logs[i][0]);
            }
        }
        sort(candidate.begin(), candidate.end());
        return candidate[0];
    }
};