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
    string mostCommonWord(string paragraph, vector<string> &banned) {
        for (auto &c : paragraph)
            c = ispunct(c) ? ' ' : c;
        int mx = 0;
        unordered_map<string, int> counter;
        stringstream ss;
        ss << paragraph;
        string s;
        while (ss >> s) {
            lowerString(s);
            counter[s]++;
        }
        for (auto itr = counter.begin(); itr != counter.end(); itr++) {
            bool yo = 1;
            for (auto &b : banned) {
                if (itr->first == b) {
                    yo = 0;
                    break;
                }
            }
            if (yo && itr->second > mx) {
                mx = itr->second;
                s = itr->first;
            }
        }
        return s;
    }

    void lowerString(string &s) {
        for (char &c : s)
            c = tolower(c);
        return;
    }
};