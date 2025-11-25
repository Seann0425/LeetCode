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
    int maximumBeauty(vector<int> &nums, int k) {
        vector<int> intervals(
            static_cast<size_t>(*max_element(nums.begin(), nums.end()) + 2 * k + 2));
        auto ans = 0, overlap = 0;
        for (const auto &i : nums) intervals[i]++, intervals[i + 2 * k + 1]--;
        for (const auto &i : intervals) {
            overlap += i;
            ans = max(ans, overlap);
        }
        return ans;
    }
};

class Solution {
public:
    int maximumBeauty(vector<int> &nums, int k) {
        const auto n = nums.size();
        auto ans = 0;
        sort(nums.begin(), nums.end());
        for (auto l = 0uz, r = 0uz; r < n; l++) {
            while (r < n && nums[r] - nums[l] <= 2 * k) r++;
            ans = max(ans, static_cast<int>(r - l));
        }
        return ans;
    }
};