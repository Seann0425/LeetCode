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

#include <ranges>
class Solution {
public:
    int minimumSumSubarray(vector<int> &nums, size_t l, size_t r) {
        for (const auto [i, num] : views::enumerate(nums) | views::drop(1)) nums[i] += nums[i - 1];
        auto ans = numeric_limits<int>::max();
        nums.insert(nums.begin(), 0);
        const auto n = nums.size();
        for (const auto [i, num] : views::enumerate(nums) | views::drop(l)) {
            for (size_t j = i - l; (j < n && i - r < n && j >= i - r) or (i - r > n && j < n);
                 j--) {
                if (auto sub = num - nums[j]; sub > 0) ans = min(ans, sub);
            }
        }
        return ans == numeric_limits<int>::max() ? -1 : ans;
    }
};