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
    int threeSumClosest(vector<int> &nums, int target) {
        const auto n = nums.size();
        auto closest = accumulate(nums.begin(), nums.begin() + 3, 0);
        sort(nums.begin(), nums.end());
        for (size_t fixed = 0; fixed < n - 2; fixed++) {
            auto left = fixed + 1, right = n - 1;
            auto best_sum = nums[fixed] + nums[left] + nums[right];
            while (left < right) {
                const auto sum = nums[fixed] + nums[left] + nums[right];
                if (abs(sum - target) < abs(best_sum - target)) best_sum = sum;
                if (sum == target) return target;
                else if (sum < target) left++;
                else right--;
            }
            if (abs(best_sum - target) < abs(closest - target)) closest = best_sum;
        }
        return closest;
    }
};