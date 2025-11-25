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
    unordered_map<string, int> dict;
    unordered_map<size_t, int> memo;
    int solve(string &s, size_t idx) {
        if (idx == s.size()) return 0;
        if (memo.find(idx) != memo.end()) return memo[idx];
        int tail = numeric_limits<int>::max();
        string tmp{};
        for (size_t i = idx; i < s.size(); i++) {
            tmp.push_back(s[i]);
            // tmp is part of the partition
            if (dict.find(tmp) != dict.end()) tail = min(tail, solve(s, i + 1));
        }
        // idx is one of the extra char
        tail = min(tail, 1 + solve(s, idx + 1));
        memo[idx] = tail;
        return memo[idx];
    }
public:
    int minExtraChar(string s, vector<string> &dictionary) {
        for (auto &word : dictionary) dict[std::move(word)]++;
        return solve(s, 0uz);
    }
};