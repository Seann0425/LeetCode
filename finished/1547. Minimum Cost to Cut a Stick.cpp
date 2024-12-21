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
    array<array<int, 105>, 105> dp;
    int dfs(const vector<int> &cuts, size_t l, size_t r) {
        if (r - l <= 1) return 0;
        if (dp[l][r]) return dp[l][r];
        dp[l][r] = numeric_limits<int>::max();
        for (size_t i = l + 1; i < r; i++)
            dp[l][r] = min(dp[l][r], cuts[r] - cuts[l] + dfs(cuts, l, i) + dfs(cuts, i, r));
        return dp[l][r];
    }
public:
    int minCost(int n, vector<int> &cuts) {
        cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return dfs(cuts, 0uz, cuts.size() - 1);
    }
};