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
    long long maxScore(vector<int> &nums1, vector<int> &nums2, int k) {
        const auto n = nums1.size();
        vector<size_t> nums(n);
        iota(nums.begin(), nums.end(), 0);
        sort(nums.begin(), nums.end(), [&](auto &i, auto &j) { return nums2[i] > nums2[j]; });
        auto ans = numeric_limits<long long>::min(), sum = 0ll; // sum of kth-greatest elements
        priority_queue<int, vector<int>, greater<int>> kth_greatest;
        for (const auto &i : nums | std::views::take(k - 1)) {
            sum += nums1[i];
            kth_greatest.push(nums1[i]);
        }
        for (const auto &i : nums | std::views::drop(k - 1)) {
            sum += nums1[i];
            kth_greatest.push(nums1[i]);
            ans = max(ans, sum * nums2[i]);
            sum -= kth_greatest.top();
            kth_greatest.pop();
        }
        return ans;
    }
};