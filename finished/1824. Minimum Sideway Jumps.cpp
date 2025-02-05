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
    int minSideJumps(vector<int> &obstacles) {
        const auto n = obstacles.size();
        array<int, 3> inf;
        inf.fill(numeric_limits<int>::max());
        vector dp(n, inf);
        dp[0][0] = dp[0][2] = 1;
        dp[0][1] = 0;
        for (auto i = 1; i < n; i++) {
            for (auto o = 0; o < 3; o++) {
                if (obstacles[i] == o + 1 or obstacles[i - 1] == o + 1) continue;
                dp[i][o] = dp[i - 1][o];
            }
            for (auto o = 0; o < 3; o++) {
                if (obstacles[i] == o + 1) continue;
                if (dp[i][(o + 1) % 3] != numeric_limits<int>::max()) {
                    dp[i][o] = min(dp[i][o], dp[i][(o + 1) % 3] + 1);
                }
                if (dp[i][(o + 2) % 3] != numeric_limits<int>::max()) {
                    dp[i][o] = min(dp[i][o], dp[i][(o + 2) % 3] + 1);
                }
            }
        }
        return *min_element(dp.back().begin(), dp.back().end());
    }
};