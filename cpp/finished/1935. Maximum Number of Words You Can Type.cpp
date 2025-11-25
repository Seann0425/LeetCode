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
    int canBeTypedWords(string text, string brokenLetters) {
        int counter = 0;
        stringstream ss;
        ss << text;
        string word;
        while (ss >> word) {
            vector<int> alpha(26, 0);
            for (char c : word)
                alpha[c - 'a']++;
            bool b = true;
            for (char c : brokenLetters) {
                if (alpha[c - 'a'] > 0) {
                    b = false;
                    break;
                }
            }
            if (b) counter++;
        }
        return counter;
    }
};