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
    long long max_subarray_sum(const vector<long long> &nums) {
        if (nums.empty()) return numeric_limits<long long>::min();
        long long ans = nums[0];
        long long sum = nums[0];
        for (const auto &num : nums | views::drop(1)) {
            sum = max(num, sum + num);
            ans = max(ans, sum);
        }
        return ans;
    }
public:
    long long maxSubarraySum(vector<int> &nums, size_t k) {
        const auto n = nums.size();
        vector windows_sum(k, vector<long long>());
        auto window = accumulate(nums.begin(), nums.begin() + k, 0ll);
        windows_sum[0].push_back(window);
        for (size_t i = 1; i <= n - k; i++) {
            window += nums[i + k - 1] - nums[i - 1];
            windows_sum[i % k].push_back(window);
        }

        // find the maximum subarray sum among windows_sum
        auto ans = windows_sum[0][0];
        for (const auto &window_sum : windows_sum) ans = max(ans, max_subarray_sum(window_sum));
        return ans;
    }
};