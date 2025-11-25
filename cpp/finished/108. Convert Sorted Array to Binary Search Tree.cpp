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

/*the solution should start from below*/

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
    vector<int> nums;
    size_t n;
    TreeNode *get_node(size_t left, size_t right) {
        if (left > right or right >= n) return nullptr;
        size_t mid = left + (right - left) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        node->left = get_node(left, mid - 1);
        node->right = get_node(mid + 1, right);
        return node;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &nums) {
        this->nums = std::move(nums);
        n = this->nums.size();
        return get_node(0, n - 1);
    }
};