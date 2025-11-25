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
    bool isPowerOfTwo(int n) {
        if (n < 0) return false;
        unsigned int trans = (unsigned)n;
        trans = (trans & 0x55555555) + ((trans & 0xaaaaaaaa) >> 1);
        trans = (trans & 0x33333333) + ((trans & 0xcccccccc) >> 2);
        trans = (trans & 0x0f0f0f0f) + ((trans & 0xf0f0f0f0) >> 4);
        trans = (trans & 0x00ff00ff) + ((trans & 0xff00ff00) >> 8);
        trans = (trans & 0x0000ffff) + ((trans & 0xffff0000) >> 16);
        if (trans == 1) return true;
        return false;
    }
};