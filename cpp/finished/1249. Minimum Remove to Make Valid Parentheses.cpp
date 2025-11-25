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
    string minRemoveToMakeValid(string s) {
        stack<size_t> parenthesis;
        for (size_t i = 0; i < s.size(); i++) {
            auto &c = s[i];
            if (c == '(') parenthesis.push(i);
            else if (c == ')') {
                if (!parenthesis.empty()) parenthesis.pop();
                else c = 'X';
            }
        }
        while (!parenthesis.empty()) {
            s[parenthesis.top()] = 'X';
            parenthesis.pop();
        }
        erase_if(s, [](const char c) { return c == 'X'; });
        return s;
    }
};