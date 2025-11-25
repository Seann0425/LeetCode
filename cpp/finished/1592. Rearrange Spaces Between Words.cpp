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
    string reorderSpaces(string text) {
        int words = 0, spaces = 0;
        char pre = ' ';
        for (char c : text) {
            if (c != ' ' && pre == ' ') words++;
            else if (c == ' ') spaces++;
            pre = c;
        }
        int len = (words != 1) ? (spaces / (words - 1)) : spaces;
        string cpy = text;
        string res;
        stringstream ss;
        ss << cpy;
        while (ss >> cpy) {
            res += cpy;
            for (int i = 0; i < len; i++)
                res += ' ';
        }
        while (res.size() > text.size())
            res.pop_back();
        while (res.size() < text.size())
            res.push_back(' ');
        return res;
    }
};