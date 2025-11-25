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
    int calPoints(vector<string> &operations) {
        int sum = 0, pre = 0, cur = 0;
        stack<int> sad;
        for (auto x : operations) {
            if (x == "+") {
                sum += (pre + cur);
                sad.push((pre + cur));
                int tmp = cur;
                cur += pre;
                pre = tmp;
            } else if (x == "D") {
                sum += (cur * 2);
                sad.push((cur * 2));
                pre = cur;
                cur *= 2;
            } else if (x == "C") {
                sum -= cur;
                cur = pre;
                sad.pop();
                if (!sad.empty()) sad.pop();
                if (sad.empty()) pre = 0;
                else pre = sad.top();
                sad.push(cur);
            } else {
                sum += stoi(x);
                pre = cur;
                cur = stoi(x);
                sad.push(stoi(x));
            }
        }
        return sum;
    }
};