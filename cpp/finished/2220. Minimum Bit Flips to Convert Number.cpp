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
    int minBitFlips(unsigned start, unsigned goal) {
        return popcount(start ^ goal);
    }
};

// class Solution {
// public:
//     int minBitFlips(int start, int goal) {
//         unsigned cnt = start ^ goal;
//         cnt = (cnt & 0x55555555) + ((cnt & 0xaaaaaaaa) >> 1);
//         cnt = (cnt & 0x33333333) + ((cnt & 0xcccccccc) >> 2);
//         cnt = (cnt & 0x0f0f0f0f) + ((cnt & 0xf0f0f0f0) >> 4);
//         cnt = (cnt & 0x00ff00ff) + ((cnt & 0xff00ff00) >> 8);
//         cnt = (cnt & 0x0000ffff) + ((cnt & 0xffff0000) >> 16);
//         return cnt;
//     }
// };