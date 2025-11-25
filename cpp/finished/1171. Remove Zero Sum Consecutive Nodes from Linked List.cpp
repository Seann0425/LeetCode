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
    ListNode *removeZeroSumSublists(ListNode *head) {
        deque<int> nodes;
        unordered_set<int> prefix;
        int prefix_sum = 0;
        ListNode *cur = head;
        prefix.insert(0);
        while (cur) {
            prefix_sum += cur->val;
            nodes.push_back(cur->val);
            cur = cur->next;
            if (prefix.find(prefix_sum) != prefix.end()) {
                int val = prefix_sum;
                while (!nodes.empty()) {
                    prefix.erase(prefix_sum);
                    prefix_sum -= nodes.back();
                    nodes.pop_back();
                    if (val == prefix_sum) break;
                }
            }
            prefix.insert(prefix_sum);
        }
        ListNode *new_head = nullptr, *mover = nullptr;
        while (!nodes.empty()) {
            if (new_head == nullptr) {
                new_head = new ListNode(nodes.front());
                mover = new_head;
            } else {
                mover->next = new ListNode(nodes.front());
                mover = mover->next;
            }
            nodes.pop_front();
        }
        return new_head;
    }
};