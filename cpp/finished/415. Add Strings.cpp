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
    string addStrings(string num1, string num2) {
        string lazy = "";
        int n1 = num1.size(), n2 = num2.size();
        int carry = 0;
        while (n1 && n2) {
            n1--, n2--;
            int tmp = (num1[n1] - '0') + (num2[n2] - '0') + carry;
            lazy = (char)(tmp % 10 + '0') + lazy;
            carry = tmp / 10;
        }
        while (n1--) {
            int tmp = (num1[n1] - '0') + carry;
            lazy = (char)(tmp % 10 + '0') + lazy;
            carry = tmp / 10;
        }
        while (n2--) {
            int tmp = (num2[n2] - '0') + carry;
            lazy = (char)(tmp % 10 + '0') + lazy;
            carry = tmp / 10;
        }
        if (carry) lazy = (char)(carry + '0') + lazy;
        return lazy;
    }
};