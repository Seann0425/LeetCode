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

class MyStack {
public:
    queue<int> q1, q2;
    MyStack() {
    }

    void push(int x) {
        if (q2.empty()) q1.push(x);
        else q2.push(x);
        return;
    }

    int pop() {
        if (q2.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int pop = q1.front();
            q1.pop();
            return pop;
        }
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        int pop = q2.front();
        q2.pop();
        return pop;
    }

    int top() {
        if (q2.empty()) {
            while (q1.size() > 1) {
                q2.push(q1.front());
                q1.pop();
            }
            int pop = q1.front();
            q1.pop();
            q2.push(pop);
            return pop;
        }
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
        int pop = q2.front();
        q2.pop();
        q1.push(pop);
        return pop;
    }

    bool empty() {
        if (q1.empty() && q2.empty()) return true;
        return false;
    }
};