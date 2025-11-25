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
    ListNode *removeNodes(ListNode *head) {
        deque<ListNode *> mono;
        for (ListNode *cur = head; cur; cur = cur->next) {
            while (!mono.empty() && mono.back()->val < cur->val)
                mono.pop_back();
            mono.push_back(cur);
        }
        ListNode *cur = head, *prev = nullptr;
        while (cur) {
            if (!mono.empty() && cur == mono.front()) {
                mono.pop_front();
                prev = cur;
                cur = cur->next;
                continue;
            }
            if (!prev) {
                head = cur->next;
                cur = head;
            } else {
                prev->next = cur->next;
                cur = cur->next;
            }
        }
        return head;
    }
};