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
    bool rotateString(string s, string goal) {
        if (goal.size() != s.size()) return false;
        s += s;
        return s.find(goal) != string::npos;
    }
};

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         const auto n = s.size(), g = goal.size();
//         if (n != g) return false;
//         for (size_t i = 0; i < n; i++) {
//             if (s[i] == goal[0]) {
//                 for (size_t j = 0; j < g; j++) {
//                     if (goal[j] != s[(i + j) % n]) goto failed;
//                 }
//                 return true;
//             }
//         failed:
//             continue;
//         }
//     }
// };

// class Solution {
// public:
//     bool rotateString(string s, string goal) {
//         ios_base::sync_with_stdio(0);
//         int n = s.size(), g = goal.size();
//         if (n != g) return false;
//         for (int i = 0; i < n; i++) {
//             if (s[i] == goal[0]) {
//                 bool r = 1;
//                 for (int j = 0; j < g; j++) {
//                     if (goal[j] != s[(i + j) % n]) {
//                         r = 0;
//                         break;
//                     }
//                 }
//                 if (r) return true;
//             }
//         }
//         return false;
//     }
// };