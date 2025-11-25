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
    int hammingDistance(int x, int y) {
        int ans = x ^ y;
        ans = (ans & 0x55555555) + ((ans & 0xaaaaaaaa) >> 1);
        ans = (ans & 0x33333333) + ((ans & 0xcccccccc) >> 2);
        ans = (ans & 0x0f0f0f0f) + ((ans & 0xf0f0f0f0) >> 4);
        ans = (ans & 0x00ff00ff) + ((ans & 0xff00ff00) >> 8);
        ans = (ans & 0x0000ffff) + ((ans & 0xffff0000) >> 16);
        return ans;
    }
};