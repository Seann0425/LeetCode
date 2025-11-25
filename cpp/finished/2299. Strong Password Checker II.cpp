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
    bool isSpecial(const char &ch) {
        string spec = "!@#$%^&*()-+";
        if (spec.find(ch) != string::npos) return true;
        return false;
    }

    void Check(const char &target, bool &upper, bool &lower, bool &digit, bool &special) {
        if (isupper(target)) upper = true;
        else if (islower(target)) lower = true;
        else if (isdigit(target)) digit = true;
        else if (isSpecial(target)) special = true;
        return;
    }
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        bool upperCheck = false, lowerCheck = false, digitCheck = false, specialCheck = false;
        for (int i = 1; i < password.size(); i++) {
            if (password[i] == password[i - 1]) return false;
            Check(password[i], upperCheck, lowerCheck, digitCheck, specialCheck);
        }
        Check(password[0], upperCheck, lowerCheck, digitCheck, specialCheck);
        if (upperCheck && lowerCheck && digitCheck && specialCheck) return true;
        else return false;
    }
};