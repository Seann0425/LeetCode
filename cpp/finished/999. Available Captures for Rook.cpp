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
    int numRookCaptures(vector<vector<char>> &board) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int x, y;
        int attacking = 0;
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x = j;
                    y = i;
                    goto afterFound;
                }
            }
        }
    afterFound:
    Up:
        for (int i = y - 1; i >= 0; i--) {
            if (board[i][x] == '.') continue;
            if (board[i][x] == 'p') attacking++;
            goto Down;
        }
    Down:
        for (int i = y + 1; i < 8; i++) {
            if (board[i][x] == '.') continue;
            if (board[i][x] == 'p') attacking++;
            goto Left;
        }
    Left:
        for (int i = x - 1; i >= 0; i--) {
            if (board[y][i] == '.') continue;
            if (board[y][i] == 'p') attacking++;
            goto Right;
        }
    Right:
        for (int i = x + 1; i < 8; i++) {
            if (board[y][i] == '.') continue;
            if (board[y][i] == 'p') attacking++;
            break;
        }
        return attacking;
    }
};