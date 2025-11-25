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

// the key is to use a window with a variable size
class Solution {
public:
    long long maximumSubarraySum(vector<int> &nums, size_t k) {
        const auto n = nums.size();
        unordered_map<int, int> window;
        auto sum = 0ll, max_sum = 0ll;
        for (size_t l = 0, r = 0; r < n; r++) {
            if (!window[nums[r]]) {
                sum += nums[r];
                window[nums[r]]++;
                if (r - l + 1 == k) {
                    max_sum = max(max_sum, sum);
                    sum -= nums[l];
                    window[nums[l]]--;
                    l++;
                }
            } else {
                while (nums[l] != nums[r]) {
                    sum -= nums[l];
                    window[nums[l]]--;
                    l++;
                }
                l++;
            }
        }
        return max_sum;
    }
};