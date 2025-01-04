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
    bitset<365> travel{};
    int one, seven, thirty, last_day;
    vector<int> dp;
    int solve(int cur) {
        if (cur > last_day) return 0;
        if (dp[cur] != -1) return dp[cur];
        if (travel[cur])
            return dp[cur] = min(
                       {solve(cur + 1) + one, solve(cur + 7) + seven, solve(cur + 30) + thirty});
        return dp[cur] = solve(cur + 1);
    }
public:
    int mincostTickets(vector<int> &days, vector<int> &costs) {
        for (const auto &day : days) travel.set(day - 1);
        one = costs[0], seven = costs[1], thirty = costs[2];
        last_day = days.back();
        dp.resize(last_day + 1, -1);
        return solve(0);
    }
};