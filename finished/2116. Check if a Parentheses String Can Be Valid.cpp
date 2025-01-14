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
    bool canBeValid(string s, string locked) {
        const auto n = s.size();
        if (n % 2) return false;
        vector<size_t> opening, unlocked;
        opening.reserve(n);
        unlocked.reserve(n);
        for (auto i = 0uz; i < n; i++) {
            if (locked[i] == '0') unlocked.push_back(i);
            else if (s[i] == '(') opening.push_back(i);
            else if (!opening.empty()) opening.pop_back();
            else if (!unlocked.empty()) unlocked.pop_back();
            else return false;
        }
        while (!opening.empty() and !unlocked.empty() && opening.back() < unlocked.back()) {
            opening.pop_back();
            unlocked.pop_back();
        }
        return opening.empty();
    }
};