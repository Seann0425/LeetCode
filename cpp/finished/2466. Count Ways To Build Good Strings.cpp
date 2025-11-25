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

// bottom-up dp
class Solution {
    constexpr static int MOD = 1e9 + 7;
public:
    int countGoodStrings(size_t low, size_t high, size_t zero, size_t one) {
        vector<long long> dp(high + 1, 0ll);
        dp[0] = 1;
        for (auto i = 1uz; i <= high; i++) {
            if (i - zero < high) dp[i] = (dp[i] + dp[i - zero]) % MOD;
            if (i - one < high) dp[i] = (dp[i] + dp[i - one]) % MOD;
        }
        auto ans = 0ll;
        for (auto i = low; i <= high; i++) ans = (ans + dp[i]) % MOD;
        return static_cast<int>(ans);
    }
};