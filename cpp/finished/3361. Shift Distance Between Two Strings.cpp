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
    long long shiftDistance(string s, string t, vector<int> &nextCost, vector<int> &previousCost) {
        vector<long long> next_cost(26), previous_cost(26);
        next_cost[0] = nextCost[0];
        previous_cost[25] = previousCost[25];
        for (size_t i = 1; i < 26; i++) {
            next_cost[i] = next_cost[i - 1] + nextCost[i];
            previous_cost[25 - i] = previous_cost[26 - i] + previousCost[25 - i];
        }
        next_cost.insert(next_cost.begin(), 0);
        previous_cost.push_back(0);
        auto ans = 0ll;
        const auto n = s.size();
        for (size_t i = 0; i < n; i++) {
            if (s[i] == t[i]) continue;
            auto next = s[i] > t[i]
                            ? next_cost.back() - next_cost[s[i] - 'a'] + next_cost[t[i] - 'a']
                            : next_cost[t[i] - 'a'] - next_cost[s[i] - 'a'];
            auto previous = s[i] > t[i]
                                ? previous_cost[t[i] - 'a' + 1] - previous_cost[s[i] - 'a' + 1]
                                : previous_cost.front() - previous_cost[s[i] - 'a' + 1] +
                                      previous_cost[t[i] - 'a' + 1];
            ans += min(next, previous);
        }
        return ans;
    }
};