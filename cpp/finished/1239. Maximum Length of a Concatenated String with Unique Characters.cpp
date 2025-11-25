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
    int best = 0;
    void backTracking(int idx, int length, bitset<26> alpha, vector<string> &arr) {
        for (char c : arr[idx]) {
            if (alpha.test(c - 'a')) return;
            alpha.set(c - 'a');
        }
        length += arr[idx].size();
        if (length > best) best = length;
        for (idx += 1; idx < arr.size(); idx++) {
            backTracking(idx, length, alpha, arr);
        }
        return;
    }
public:
    int maxLength(vector<string> &arr) {
        bitset<26> alpha;
        for (int i = 0; i < arr.size(); i++)
            backTracking(i, 0, alpha, arr);
        return best;
    }
};