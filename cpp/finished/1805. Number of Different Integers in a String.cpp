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
    void clearZero(string &str) {
        while (str.size() > 1 && str.back() == '0')
            str.pop_back();
        return;
    }
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> counting;
        string cur = "";
        for (int i = word.size() - 1; i >= 0; i--) {
            if (isalpha(word[i])) {
                if (cur != "") {
                    clearZero(cur);
                    reverse(cur.begin(), cur.end());
                    counting.insert(cur);
                }
                cur = "";
            } else {
                cur.push_back(word[i]);
            }
        }
        if (cur != "") {
            clearZero(cur);
            reverse(cur.begin(), cur.end());
            counting.insert(cur);
        }
        return counting.size();
    }
};