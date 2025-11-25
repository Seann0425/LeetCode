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
    int nextGreaterElement(int n) {
        string number = to_string(n);
        int sz = number.size();
        int i, j;
        for (i = sz - 2; i >= 0; i--)
            if (number[i] - '0' < number[i + 1] - '0') break;
        if (i < 0) return -1;
        for (j = sz - 1; j >= 0; j--)
            if (number[j] - '0' > number[i] - '0') break;
        swap(number[i], number[j]);
        sort(number.begin() + i + 1, number.end());
        long long ans = stoll(number);
        return (ans > INT_MAX) ? -1 : (int)ans;
    }
};