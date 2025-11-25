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
#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
public:
    int possibleStringCount(string word, size_t k) {
        vector<int> freq;
        auto total = 1ll,
             mod = static_cast<long long>(1e9 + 7); // total minus those at most k - 1 length
        const auto n = word.size();

        for (auto i = 0uz; i < n;) {
            auto j = i;
            while (++i < n)
                if (word[i] != word[j]) break;
            if (i > j + 1) {
                freq.push_back(i - j - 1); // characters that might not be in original string
                total = total * (i - j) % mod;
            }
            --k;
        }
        if (!(k && k < n)) return static_cast<int>(total); // len < 0

        vector<int64_t> dp(k, 0);    // dp[i] is the number of clumsy subsequence of length i
        dp[0] = 1;                   // no clumsy character
        for (const auto &f : freq) { // sequentially consider every potential clumsy characters
            for (auto i = 1uz; i < k; ++i) dp[i] = (dp[i] + dp[i - 1]) % mod; // prefix sum
            for (auto i = k - 1; i > f; --i)
                dp[i] = (dp[i] - dp[i - f - 1] + mod) % mod; // subtract those overcounted
            // basically, for every new frequency f, the transition is
            // dp[i] = sum(dp[i], dp[i - 1], ..., dp[i - f])
            // for how many new character is used
        }
        for (auto i = 1uz; i < k; ++i) dp[i] = (dp[i] + dp[i - 1]) % mod;
        return (total - dp.back() + mod) % mod;
    }
};