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
    int search(vector<int> &nums, int target) {
        if (nums.front() <= nums.back()) {
            auto ans = lower_bound(nums.begin(), nums.end(), target);
            if (ans == nums.end() or *ans != target) return -1;
            return ans - nums.begin();
        }
        // find pivot
        const auto n = nums.size();
        auto l = 0uz, r = n - 1;
        while (l < r) {
            if (r - l == 1) break;
            auto m = l + (r - l) / 2;
            if (nums[m] > nums[l]) l = m;
            else r = m;
        }
        auto pivot = nums.begin() + l + 1;
        auto left = lower_bound(nums.begin(), pivot, target);
        auto right = lower_bound(pivot, nums.end(), target);
        auto not_left = *left != target or left == pivot;
        auto not_right = *right != target or right == nums.end();
        if (not_left and not_right) return -1;
        return not_left ? right - nums.begin() : left - nums.begin();
    }
};