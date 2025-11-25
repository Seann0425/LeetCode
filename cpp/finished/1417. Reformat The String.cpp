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
    string reformat(string s) {
        vector<char> A, N;
        for (char c : s) {
            if (isalpha(c)) A.push_back(c);
            else N.push_back(c);
        }
        int a = A.size(), n = N.size();
        if (abs(a - n) > 1) return "";
        string ans;
        if (a >= n) {
            while (N.size()) {
                ans.push_back(A.back());
                A.pop_back();
                ans.push_back(N.back());
                N.pop_back();
            }
            if (A.size()) ans.push_back(A.back());
        } else {
            while (A.size()) {
                ans.push_back(N.back());
                N.pop_back();
                ans.push_back(A.back());
                A.pop_back();
            }
            if (N.size()) ans.push_back(N.back());
        }
        return ans;
    }
};