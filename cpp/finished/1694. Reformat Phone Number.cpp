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
    string reformatNumber(string number) {
        int digits = 0;
        for (char c : number)
            if (isdigit(c)) digits++;
        int cnt = 0;
        string res = "";
        int cas = digits % 3;
        for (int i = 0; i < number.size(); i++) {
            if (!isdigit(number[i])) continue;
            if ((digits == 2 && cas == 2) || (digits == 3 && cas == 0)) {
                while (digits) {
                    if (isdigit(number[i])) {
                        res.push_back(number[i]);
                        digits--;
                    }
                    i++;
                }
                break;
            } else if (digits == 4 && cas == 1) {
                while (digits > 2) {
                    if (isdigit(number[i])) {
                        res.push_back(number[i]);
                        digits--;
                    }
                    i++;
                }
                res.push_back('-');
                while (digits) {
                    if (isdigit(number[i])) {
                        res.push_back(number[i]);
                        digits--;
                    }
                    i++;
                }
                break;
            } else {
                res.push_back(number[i]);
                cnt++, digits--;
                if (cnt == 3) cnt = 0, res.push_back('-');
            }
        }
        return res;
    }
};