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
    vector<vector<int>> ans{};
    size_t n{};
    void two_sum(const vector<int> &nums, size_t start, long long target, int i, int j) {
        unordered_map<long long, bool> seen{};
        for (auto k = start; k < n; k++) {
            auto complement = target - nums[k];
            if (seen.contains(complement) and !seen[complement]) {
                ans.push_back({i, j, nums[k], static_cast<int>(complement)});
                seen[complement] = true;
            }
            seen.emplace(nums[k], false);
        }
    }
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        n = nums.size();
        for (auto i = 0uz; i < n; i++) {
            if (i && nums[i] == nums[i - 1]) continue;
            for (auto j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                auto sum = 0ll + target - nums[i] - nums[j];
                two_sum(nums, j + 1, sum, nums[i], nums[j]);
            }
        }
        return ans;
    }
};