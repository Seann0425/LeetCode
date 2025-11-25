#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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

// 難しすぎ
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        const auto n = piles.size();
        vector<int> suffix(n);
        vector<vector<int>> dp(n, vector<int>(n + 1, 0));

        suffix[n - 1] = piles[n - 1];
        for (size_t i = n - 2; i < n; i--)
            suffix[i] = suffix[i + 1] + piles[i];

        for (size_t i = n - 1; i < n; i--) {
            for (size_t m = 1; m <= n; m++) {
                if (i + 2 * m >= n) dp[i][m] = suffix[i];
                else for (size_t x = 1; x <= 2 * m; x++) dp[i][m] = max(dp[i][m], suffix[i] - dp[i + x][max(m, x)]);
            }
        } 

        return dp[0][1];
    }
};