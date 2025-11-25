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
    int findLeader(vector<int> &belongs, int follower) {
        if (belongs[follower] == follower) return follower;
        else {
            belongs[follower] = findLeader(belongs, belongs[follower]);
            return belongs[follower];
        }
    }

    void merge(vector<int> &belongs, int leader, int follower) {
        int L1 = findLeader(belongs, leader);
        int L2 = findLeader(belongs, follower);

        if (L1 != L2) belongs[L2] = L1;
        return;
    }
public:
    int findCircleNum(vector<vector<int>> &isConnected) {
        int n = isConnected.size();
        vector<int> belongs(n);
        for (int i = 0; i < n; i++)
            belongs[i] = i;

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++)
                if (isConnected[i][j]) merge(belongs, i, j);
        }

        int cnt = 0;
        for (int i = 0; i < n; i++)
            if (belongs[i] == i) cnt++;
        return cnt;
    }
};