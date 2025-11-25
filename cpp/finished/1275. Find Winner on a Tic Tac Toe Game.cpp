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
    string tictactoe(vector<vector<int>> &moves) {
        vector<vector<int>> table(3, {0, 0, 0});
        for (int i = 0; i < moves.size(); i++) {
            table[moves[i][0]][moves[i][1]] = (i % 2) + 1;
        }
        for (int i = 0; i < 3; i++) {
            if (table[i][0] != 0 && table[i][0] == table[i][1] && table[i][1] == table[i][2]) {
                return (table[i][0] == 1) ? "A" : "B";
            }
        }
        for (int i = 0; i < 3; i++) {
            if (table[0][i] != 0 && table[0][i] == table[1][i] && table[1][i] == table[2][i]) {
                return (table[0][i] == 1) ? "A" : "B";
            }
        }
        if (table[0][0] != 0 && table[0][0] == table[1][1] && table[1][1] == table[2][2]) return (table[0][0] == 1) ? "A" : "B";
        if (table[0][2] != 0 && table[0][2] == table[1][1] && table[1][1] == table[2][0]) return (table[0][2] == 1) ? "A" : "B";
        return (moves.size() == 9) ? "Draw" : "Pending";
    }
};