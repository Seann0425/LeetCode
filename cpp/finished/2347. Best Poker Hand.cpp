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
    string bestHand(vector<int> &ranks, vector<char> &suits) {
        unordered_set<char> flush;
        for (const auto &s : suits)
            flush.insert(s);
        if (flush.size() == 1) return "Flush";
        unordered_map<int, int> mp;
        bool pair = false;
        for (const auto &r : ranks) {
            mp[r]++;
            if (mp[r] == 3) return "Three of a Kind";
            if (mp[r] == 2) pair = true;
        }
        if (pair) return "Pair";
        return "High Card";
    }
};