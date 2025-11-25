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
    int minSubarray(vector<int> &nums, int p) {
        const auto n = nums.size();
        int mod = 0;
        for (auto &i : nums) {
            i %= p;
            mod = (mod + i) % p;
        }
        unordered_map<int, int> two_sum;
        int prefix = 0, min_len = static_cast<int>(n);
        two_sum.emplace(0, -1);
        for (int i = 0; i < n; i++) {
            prefix = (prefix + nums[i]) % p;
            two_sum[prefix] = i;
            const auto target = (prefix - mod + p) % p;
            if (two_sum.count(target)) min_len = min(min_len, i - two_sum[target]);
            if (!min_len) return 0;
        }
        return min_len == n ? -1 : min_len;
    }
};