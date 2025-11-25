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
    int countValidWords(string sentence) {
        int cnt = 0;
        stringstream ss;
        ss << sentence;
        string word;
        while (ss >> word) {
            bool hyphen = false;
            bool valid = true;
            for (int i = 0; i < word.size(); i++) {
                if (word[i] == '-') {
                    if (hyphen) {
                        valid = false;
                        break;
                    }
                    if (i == 0 || !isalpha(word[i - 1])) {
                        valid = false;
                        break;
                    }
                    if (i == word.size() - 1 || !isalpha(word[i + 1])) {
                        valid = false;
                        break;
                    }
                    hyphen = true;
                } else if (word[i] == '!' || word[i] == '.' || word[i] == ',') {
                    if (i != word.size() - 1) {
                        valid = false;
                        break;
                    }
                } else if (isdigit(word[i])) {
                    valid = false;
                    break;
                }
            }
            if (valid) cnt++;
        }
        return cnt;
    }
};