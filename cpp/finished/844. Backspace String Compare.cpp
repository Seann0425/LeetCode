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
    bool backspaceCompare(string s, string t) {
        int nS = 0, nT = 0;
        int i, j;
        for (i = s.size() - 1, j = t.size() - 1; i >= 0 || j >= 0; i--, j--) {
            while (i >= 0) {
                if (s[i] == '#') nS++, i--;
                else if (nS > 0) nS--, i--;
                else break;
            }
            while (j >= 0) {
                if (t[j] == '#') nT++, j--;
                else if (nT > 0) nT--, j--;
                else break;
            }
            if (i >= 0 && j >= 0 && s[i] != t[j]) return false;
            if ((i >= 0) ^ (j >= 0)) return false;
        }
        return true;
    }
};