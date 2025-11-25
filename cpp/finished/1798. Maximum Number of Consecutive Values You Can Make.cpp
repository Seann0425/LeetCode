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

// counting sort
class Solution {
    static constexpr size_t max_n = 40001;
public:
    int getMaximumConsecutive(vector<int> &coins) {
        array<int, max_n> cnt{};
        for (const auto &c : coins) cnt[c]++;
        auto ans = 1;
        for (auto i = 1uz; i < max_n; i++)
            while (cnt[i]--) {
                if (ans < i) break;
                ans += i;
            }
        return ans;
    }
};

class Solution {
public:
    int getMaximumConsecutive(vector<int> &coins) {
        sort(coins.begin(), coins.end());
        auto ans = 1;
        for (auto coin : coins) {
            if (coin > ans) break;
            ans += coin;
        }
        return ans;
    }
};