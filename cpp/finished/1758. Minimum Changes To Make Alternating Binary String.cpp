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
    int minOperations(string s) {
        bool alternating = true;
        int pos[4] = {0};
        // pos[0], evenZero, pos[1], oddZero, pos[2], evenOne, pos[3], oddOne
        pos[(2 * (s[0] - '0'))]++;
        for (int i = 1; i < s.size(); i++) {
            if (s[i] == s[i - 1]) alternating = false;
            pos[(2 * (s[i] - '0')) + (i % 2)]++;
        }
        if (alternating) return 0;
        else return min(pos[1] + pos[2], pos[0] + pos[3]);
    }
};