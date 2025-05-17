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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

#include <ranges>
class Solution {
    bool check(const string &a, const string &b) {
        if (a.size() != b.size()) return false;
        auto d = 0;
        for (const auto &[i, j] : views::zip(a, b))
            if (i != j && ++d > 1) return false;
        return d == 1;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string> &words, vector<int> &groups) {
        const auto n = words.size();
        vector<int> dp(n, 1);
        vector<size_t> prev(n, n);
        vector<string> ans;
        auto max_id = 0uz;
        for (auto i = 1; i < n; ++i) {
            for (auto j = 0; j < i; ++j) {
                if (check(words[i], words[j]) && dp[j] + 1 > dp[i] && groups[i] != groups[j]) {
                    dp[i] = dp[j] + 1;
                    prev[i] = j;
                }
            }
            if (dp[i] > dp[max_id]) max_id = i;
        }
        while (max_id != n) {
            ans.push_back(words[max_id]);
            max_id = prev[max_id];
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};