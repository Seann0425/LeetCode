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
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        if (word[0] >= 'A' && word[0] <= 'Z') {
            if (word[1] >= 'A' && word[1] <= 'Z') {
                for (int i = 2; i < n; i++)
                    if (word[i] < 'A' || word[i] > 'Z') return false;
            } else {
                for (int i = 2; i < n; i++)
                    if (word[i] < 'a' || word[i] > 'z') return false;
            }
        } else {
            for (int i = 1; i < n; i++)
                if (word[i] < 'a' || word[i] > 'z') return false;
        }
        return true;
    }
};