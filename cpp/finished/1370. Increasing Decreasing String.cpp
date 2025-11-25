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
    string sortString(string s) {
        vector<int> count(26, 0);
        for (char c : s)
            count[c - 'a']++;
        int n = s.size();
        string result;
        while (n) {
            for (int i = 0; i < 26 && n; i++) {
                if (count[i]) {
                    result.push_back('a' + i);
                    count[i]--;
                    n--;
                }
            }
            for (int i = 25; i >= 0 && n; i--) {
                if (count[i]) {
                    result.push_back('a' + i);
                    count[i]--;
                    n--;
                }
            }
        }
        return result;
    }
};