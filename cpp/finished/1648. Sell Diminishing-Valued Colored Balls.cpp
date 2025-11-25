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
    static constexpr long long MOD = 1e9 + 7;
public:
    int maxProfit(vector<int> &inventory, int orders) {
        const auto n = inventory.size();
        auto ans = 0ll;
        sort(inventory.begin(), inventory.end());
        auto l = 0, r = inventory.back(), cnt = 0;
        while (l < r) {
            const auto m = l + (r - l) / 2;
            auto tmp = 0ll;
            for (const auto &i : inventory) {
                if (i > m) tmp += i - m;
                if (tmp > orders) {
                    l = m + 1;
                    continue;
                }
            }
            if (tmp <= orders) r = m, cnt = tmp;
            else l = m + 1;
        }
        for (const auto &i : inventory)
            if (i > r) ans = (ans + (static_cast<long long>(i + r + 1) * (i - r) / 2 % MOD)) % MOD;
        ans = (ans + r * static_cast<long long>(orders - cnt) % MOD) % MOD;
        return ans;
    }
};