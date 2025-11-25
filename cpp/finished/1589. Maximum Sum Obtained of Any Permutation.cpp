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
    static constexpr int mod = 1e9 + 7;
public:
    int maxSumRangeQuery(vector<int> &nums, vector<vector<int>> &requests) {
        const auto n = nums.size();
        vector<int> count(n);
        for (const auto &r : requests) {
            count[r[1]]++;
            if (r[0]) count[r[0] - 1]--;
        }
        for (auto i = n - 2; i < n; i--) count[i] += count[i + 1];
        sort(nums.begin(), nums.end());
        sort(count.begin(), count.end());
        auto ans = 0ll;
        for (auto i = 0; i < n; i++) ans = (ans + static_cast<long long>(nums[i]) * count[i]) % mod;
        return static_cast<int>(ans);
    }
};
