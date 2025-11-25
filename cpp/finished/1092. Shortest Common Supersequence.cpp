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

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        const auto m = str1.size(), n = str2.size();
        vector<vector<size_t>> dp(
            m + 1, vector<size_t>(
                       n + 1)); // dp[i][j] is the length of the scs of str1[0..i) and str2[0..j)
        for (auto i = 0uz; i <= m; ++i) dp[i][0] = i;
        for (auto i = 0uz; i <= n; ++i) dp[0][i] = i;
        for (auto i = 1uz; i <= m; ++i)
            for (auto j = 1uz; j <= n; ++j)
                if (str1[i - 1] == str2[j - 1]) dp[i][j] = dp[i - 1][j - 1] + 1;
                else dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + 1;
        string ans{};
        auto i = m, j = n;
        while (i and j) {
            if (str1[i - 1] == str2[j - 1]) {
                ans.push_back(str1[i - 1]);
                --i;
                --j;
            } else if (dp[i - 1][j] < dp[i][j - 1]) ans.push_back(str1[--i]);
            else ans.push_back(str2[--j]);
        }
        while (i) ans.push_back(str1[--i]);
        while (j) ans.push_back(str2[--j]);
        ranges::reverse(ans);
        return ans;
    }
};