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

// lazy O(nk) solution, could be optimized with sliding window
#include <ranges>
class Solution {
public:
    bool hasIncreasingSubarrays(vector<int> &nums, size_t k) {
        const auto n = nums.size();
        for (const auto [i, num] : views::enumerate(nums) | views::take(n - 2 * k + 1)) {
            bool valid = true;
            for (size_t j = i; j < i + k - 1 && valid; j++)
                if (nums[j] >= nums[j + 1]) valid = false;
            for (size_t j = i + k; j < i + 2 * k - 1 && valid; j++)
                if (nums[j] >= nums[j + 1]) valid = false;
            if (valid) return true;
        }
        return false;
    }
};