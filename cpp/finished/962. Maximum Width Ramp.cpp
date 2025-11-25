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
    int maxWidthRamp(vector<int> &nums) {
        const auto n = nums.size();
        vector<size_t> mono;
        auto ans = 0;
        mono.reserve(n);
        for (size_t i = 0; i < n; i++) {
            while (!mono.empty() && nums[i] >= nums[mono.back()]) mono.pop_back();
            mono.push_back(i);
        }

        for (size_t i = 0; i < n; i++) {
            auto first =
                lower_bound(mono.rbegin(), mono.rend(), i,
                            [&](const auto &a, const auto &b) { return nums[a] < nums[b]; });
            if (first == mono.rend()) continue;
            ans = max(ans, static_cast<int>(*first - i));
        }

        return ans;
    }
};
