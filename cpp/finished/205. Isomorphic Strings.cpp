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
    bool isIsomorphic(string s, string t) {
        map<char, char> dictionaryS;
        map<char, char> dictionaryT;
        for (int i = 0; i < s.size(); i++) {
            if (!dictionaryS.count(s[i])) dictionaryS[s[i]] = t[i];
            else if (t[i] != dictionaryS[s[i]]) return false;
            if (!dictionaryT.count(t[i])) dictionaryT[t[i]] = s[i];
            else if (s[i] != dictionaryT[t[i]]) return false;
        }
        return true;
    }
};