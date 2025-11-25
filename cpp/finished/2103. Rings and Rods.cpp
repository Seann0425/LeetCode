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
    int countPoints(string rings) {
        vector<bool> rods(30, false);
        for (int i = 0; i < rings.size(); i += 2) {
            int color;
            if (rings[i] == 'R') color = 0;
            else if (rings[i] == 'G') color = 1;
            else color = 2;
            rods[(rings[i + 1] - '0') * 3 + color] = true;
        }
        int cnt = 0;
        for (int i = 0; i < 30; i += 3) {
            if (rods[i] && rods[i + 1] && rods[i + 2]) cnt++;
        }
        return cnt;
    }
};