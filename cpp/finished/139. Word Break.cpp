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
    vector<char> dp;
    bool get_word_break(string &s, size_t i, unordered_set<string_view> &dict) {
        if (dp[i] != 2) return dp[i];
        for (size_t j = i; j < s.size(); j++) {
            if (dict.count(string_view(s.begin() + i, s.begin() + j + 1)) &&
                get_word_break(s, j + 1, dict))
                return dp[i] = 1;
        }
        return dp[i] = 0;
    }
public:
    bool wordBreak(string s, vector<string> &wordDict) {
        const auto n = s.size();
        dp.resize(n + 1, 2); // dp[i] = true if s[i, n) can be segmented into words
        dp.back() = 1;
        unordered_set<string_view> dict(wordDict.begin(), wordDict.end());
        return get_word_break(s, 0, dict);
    }
};