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
    int bitsCounter(int h, int m) {
        int B = (h << 6) | m;
        B = (B & 0x55555555) + ((B & 0xaaaaaaaa) >> 1);
        B = (B & 0x33333333) + ((B & 0xcccccccc) >> 2);
        B = (B & 0x0f0f0f0f) + ((B & 0xf0f0f0f0) >> 4);
        B = (B & 0x00ff00ff) + ((B & 0xff00ff00) >> 8);
        B = (B & 0x0000ffff) + ((B & 0xffff0000) >> 16);
        return B;
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> moments;
        for (int h = 0; h < 12; h++) {
            for (int m = 0; m < 60; m++) {
                if (bitsCounter(h, m) == turnedOn) {
                    moments.push_back(to_string(h) + ((m < 10) ? ":0" : ":") + to_string(m));
                }
            }
        }
        return moments;
    }
};