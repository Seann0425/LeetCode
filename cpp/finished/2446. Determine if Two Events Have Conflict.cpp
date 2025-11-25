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
    int toValue(string bruh) {
        return 60 * stoi(bruh.substr(0, 2)) + stoi(bruh.substr(3, 2));
    }
public:
    bool haveConflict(vector<string> &event1, vector<string> &event2) {
        int bruh1 = toValue(event1[0]), bruh2 = toValue(event1[1]);
        int bruh3 = toValue(event2[0]), bruh4 = toValue(event2[1]);
        if (bruh1 > bruh3) {
            swap(bruh1, bruh3);
            swap(bruh2, bruh4);
        }
        return (bruh3 <= bruh2);
    }
};