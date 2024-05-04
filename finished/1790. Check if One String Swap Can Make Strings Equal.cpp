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
    bool isClear(vector<int> &v) {
        for (int i = 0; i < 26; i++)
            if (v[i] != 0) return false;
        return true;
    }
public:
    bool areAlmostEqual(string s1, string s2) {
        vector<int> counting(26, 0);
        int difference = 0;
        for (int i = 0; i < s1.size(); i++) {
            counting[s1[i] - 'a']++;
            counting[s2[i] - 'a']--;
            if (s1[i] != s2[i]) difference++;
            if (difference > 2) return false;
        }
        return difference == 0 || (difference == 2 && isClear(counting));
    }
};