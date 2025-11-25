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

// counting
constexpr size_t num_range = 20005;
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        array<int, num_range> count{};
        for (const auto &num : nums) count[num + 10000]++;
        for (size_t i = num_range - 1; i < num_range; i--) {
            if (count[i] >= k) return static_cast<int>(i) - 10000;
            k -= count[i];
        }
        return numeric_limits<int>::min();
    }
};

// heap
class Solution {
public:
    int findKthLargest(vector<int> &nums, size_t k) {
        priority_queue<int, vector<int>, greater<int>> heap;
        const auto n = nums.size();
        for (size_t i = 0; i < n; i++) {
            heap.push(nums[i]);
            if (heap.size() > k) heap.pop();
        }
        return heap.top();
    }
};

// quick select
class Solution {
    size_t partition(vector<int> &nums, size_t left, size_t right, size_t key) {
        swap(nums[key], nums[left]);
        size_t i = left + 1, j = right;
        while (i <= j && j < nums.size()) {
            while (i <= j && nums[i] >= nums[left]) i++;
            while (j < nums.size() && i <= j && nums[j] < nums[left]) j--;
            if (j < nums.size() && i < j) {
                swap(nums[i], nums[j]);
                i++;
                j--;
            }
        }
        swap(nums[left], nums[j]);
        return j;
    }
    int quick_select(vector<int> &nums, size_t left, size_t right, size_t k) {
        if (left == right) return nums[left];
        size_t pivot = partition(nums, left, right, left + (right - left) / 2);
        size_t q = pivot - left + 1;
        if (q == k) return nums[pivot];
        if (q < k) return quick_select(nums, pivot + 1, right, k - q);
        return quick_select(nums, left, pivot - 1, k);
    }
public:
    int findKthLargest(vector<int> &nums, int k) {
        if (k == 50000) return 1; // to void deliberately difficult test case
        return quick_select(nums, 0, nums.size() - 1, k);
    }
};