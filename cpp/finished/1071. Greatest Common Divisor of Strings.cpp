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
    string gcdOfStrings(string str1, string str2) {
        if (str1.size() == str2.size() && str1 == str2) return str1;
        else if (str1.size() == str2.size()) return "";
        if (str1.size() > str2.size()) {
            for (int i = str2.size() - 1; i >= 0; i--) {
                if (str2[i] == str1.back()) str1.pop_back();
                else return "";
            }
            return gcdOfStrings(str1, str2);
        } else {
            for (int i = str1.size() - 1; i >= 0; i--) {
                if (str1[i] == str2.back()) str2.pop_back();
                else return "";
            }
            return gcdOfStrings(str1, str2);
        }
    }
};