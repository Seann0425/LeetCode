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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string> &words) {
        bitset<26> allow;
        for (const auto &i : allowed) allow.set(i - 'a');
        int ans{};
        for (const auto &word : words) {
            bool valid = true;
            for (const auto &c : word)
                if (!allow.test(c - 'a')) {
                    valid = false;
                    break;
                }
            if (valid) ans++;
        }
        return ans;
    }
};

// class Solution {
// public:
//     int countConsistentStrings(string allowed, vector<string> &words) {
//         int num = 0;
//         unordered_set<char> ele;
//         for (char &c : allowed)
//             ele.insert(c);
//         for (string &str : words) {
//             bool push = 1;
//             for (char &c : str) {
//                 if (!ele.count(c)) {
//                     push = 0;
//                     break;
//                 }
//             }
//             if (push) num++;
//         }
//         return num;
//     }
// };