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
    int numUniqueEmails(vector<string> &emails) {
        unordered_map<string, int> SMTP;
        for (string &m : emails) {
            string processed;
            int i = 0;
            for (; m[i] != '@'; i++) {
                if (isalpha(m[i])) processed.push_back(m[i]);
                if (m[i] == '+') break;
            }
            while (m[i] != '@')
                i++;
            while (i < m.size())
                processed.push_back(m[i++]);
            SMTP[processed]++;
        }
        return SMTP.size();
    }
};