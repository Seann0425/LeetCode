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
    int minOperations(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() * 6 < nums2.size() or nums1.size() > nums2.size() * 6) return -1;
        auto sum1 = reduce(nums1.begin(), nums1.end()), sum2 = reduce(nums2.begin(), nums2.end());
        if (sum1 > sum2) swap(nums1, nums2);
        auto diff = abs(sum1 - sum2), ans = 0;
        array<int, 6> cnt{};
        for (auto &num : nums1) cnt[6 - num]++; // smaller
        for (auto &num : nums2) cnt[num - 1]++; // larger
        for (auto i = 5; i > 0 and diff > 0; i--) {
            auto take = min(cnt[i], (diff + i - 1) / i);
            diff -= take * i;
            ans += take;
        }
        return ans;
    }
};