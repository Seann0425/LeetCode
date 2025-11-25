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
    void reorderList(ListNode *head) {
        if (!head->next) return;
        stack<ListNode *> backwards;
        ListNode *cur = head;
        while (cur)
            backwards.push(cur), cur = cur->next;
        cur = head;
        ListNode *forwards = head->next;
        bool flag = true; // insert node backwards if true
        while (backwards.top() != forwards) {
            if (flag) {
                cur->next = backwards.top();
                backwards.pop();
                cur = cur->next;
            } else {
                cur->next = forwards;
                forwards = forwards->next;
                cur = cur->next;
            }
            flag = !flag;
        }
        if (flag) forwards->next = nullptr;
        else {
            cur->next = forwards;
            cur->next->next = nullptr;
        }

        return;
    }
};