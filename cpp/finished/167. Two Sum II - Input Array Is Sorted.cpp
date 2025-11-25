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
    vector<int> twoSum(vector<int> &nums, int target) {
        const auto n = nums.size();
        auto i = 0uz, j = n - 1;
        while (i < j) {
            const auto sum = nums[i] + nums[j];
            if (sum == target) return {static_cast<int>(i + 1), static_cast<int>(j + 1)};
            if (sum < target) i++;
            else j--;
        }
        return {};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int> &nums, int target) {
//         const auto n = nums.size();
//         for (auto i = 0uz; i < n; i++)
//             if (auto pair = lower_bound(nums.begin() + i + 1, nums.end(), target - nums[i]);
//                 pair != nums.end() and *pair == target - nums[i])
//                 return {static_cast<int>(i + 1), static_cast<int>(pair - nums.begin()) + 1};
//         return {};
//     }
// };