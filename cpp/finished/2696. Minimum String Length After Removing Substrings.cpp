#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    int minLength(string s) {
        stack<char> stk;
        for (const auto &ch : s) {
            if (ch == 'B' && !stk.empty() && stk.top() == 'A') stk.pop();
            else if (ch == 'D' && !stk.empty() && stk.top() == 'C') stk.pop();
            else stk.push(ch);
        }
        return static_cast<int>(stk.size());
    }
};

// class Solution {
// public:
//     int minLength(string s) {
//         stack<char> stk;
//         for (const auto &ch : s) {
//             if (!stk.empty()) {
//                 if (ch == 'B' && stk.top() == 'A') {
//                     stk.pop();
//                     continue;
//                 } else if (ch == 'D' && stk.top() == 'C') {
//                     stk.pop();
//                     continue;
//                 }
//             }
//             stk.push(ch);
//         }
//         return static_cast<int>(stk.size());
//     }
// };