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
    string reformatDate(string date) {
        string res;
        if (date.length() == 13) res = date.substr(9, 4) + '-' + ret(date.substr(5, 3)) + '-' + date.substr(0, 2);
        else res = date.substr(8, 4) + '-' + ret(date.substr(4, 3)) + '-' + '0' + date.substr(0, 1);
        return res;
    }
    string ret(string s) {
        if (s == "Jan") return "01";
        else if (s == "Feb") return "02";
        else if (s == "Mar") return "03";
        else if (s == "Apr") return "04";
        else if (s == "May") return "05";
        else if (s == "Jun") return "06";
        else if (s == "Jul") return "07";
        else if (s == "Aug") return "08";
        else if (s == "Sep") return "09";
        else if (s == "Oct") return "10";
        else if (s == "Nov") return "11";
        else return "12";
    }
};