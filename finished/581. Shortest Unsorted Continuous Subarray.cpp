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
    int findUnsortedSubarray(vector<int> &nums) {
        const auto n = nums.size();
        vector<size_t> right_small(n, numeric_limits<size_t>::max()),
            left_large(n, numeric_limits<size_t>::max());
        stack<size_t> monotonic;
        for (auto i = n - 1; i < n; i--) {
            while (!monotonic.empty() && nums[monotonic.top()] >= nums[i]) monotonic.pop();
            if (!monotonic.empty()) right_small[i] = monotonic.top();
            monotonic.push(i);
        }
        monotonic = stack<size_t>();
        for (auto i = 0; i < n; i++) {
            while (!monotonic.empty() && nums[monotonic.top()] <= nums[i]) monotonic.pop();
            if (!monotonic.empty()) left_large[i] = monotonic.top();
            monotonic.push(i);
        }
        auto l = 0uz, r = n - 1;
        while (l < n - 1 and nums[l] <= nums[l + 1] and
               right_small[l + 1] == numeric_limits<size_t>::max())
            l++;
        while (r > 0 and nums[r] >= nums[r - 1] and
               left_large[r - 1] == numeric_limits<size_t>::max())
            r--;
        auto ans = r > l ? static_cast<int>(r - l - 1) : 0;
        if (right_small[0] != numeric_limits<size_t>::max()) ans++;
        if (left_large[n - 1] != numeric_limits<size_t>::max()) ans++;
        return ans;
    }
};