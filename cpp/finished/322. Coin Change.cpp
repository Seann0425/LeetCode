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
    int coinChange(vector<int> &coins, int amount) {
        if (amount == 0) return 0;
        vector<int> DP(amount, INT_MAX);
        for (const auto &c : coins) {
            if (c - 1 >= amount) continue;
            DP[c - 1] = 1;
        }
        for (int i = 0; i < amount; i++) {
            for (const auto &c : coins) {
                if (i - c < 0 || DP[i - c] == INT_MAX) continue;
                DP[i] = min(DP[i], DP[i - c] + 1);
            }
        }
        return ((DP[amount - 1] == INT_MAX) ? -1 : DP[amount - 1]);
    }
};