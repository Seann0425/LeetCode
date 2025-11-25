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

class MyCircularQueue {
    stack<int> stk1, stk2;
    int size;
public:
    MyCircularQueue(int k) {
        size = k;
    }

    bool enQueue(int value) {
        if (stk1.size() >= size) return false;
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        stk1.push(value);
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return true;
    }

    bool deQueue() {
        if (stk1.empty()) return false;
        stk1.pop();
        return true;
    }

    int Front() {
        if (stk1.empty()) return -1;
        return stk1.top();
    }

    int Rear() {
        if (stk1.empty()) return -1;
        while (!stk1.empty()) {
            stk2.push(stk1.top());
            stk1.pop();
        }
        int rear = stk2.top();
        while (!stk2.empty()) {
            stk1.push(stk2.top());
            stk2.pop();
        }
        return rear;
    }

    bool isEmpty() {
        return stk1.empty();
    }

    bool isFull() {
        return stk1.size() == size;
    }
};