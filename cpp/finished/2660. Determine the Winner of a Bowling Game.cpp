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
    int isWinner(vector<int> &player1, vector<int> &player2) {
        const int n = player1.size();
        int P1 = 0, P2 = 0;
        for (int i = 0; i < n; i++) {
            if ((i > 0 && player1[i - 1] == 10) || (i > 1 && player1[i - 2] == 10)) P1 += 2 * player1[i];
            else P1 += player1[i];
            if ((i > 0 && player2[i - 1] == 10) || (i > 1 && player2[i - 2] == 10)) P2 += 2 * player2[i];
            else P2 += player2[i];
        }
        if (P1 > P2) return 1;
        else if (P1 < P2) return 2;
        else return 0;
    }
};