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
    int countValidSelections(vector<int> &nums) {
        const auto n = nums.size();
        vector<int> prefix(n);
        prefix[0] = nums[0];
        auto ans = 0;
        for (const auto [i, num] : views::enumerate(nums) | views::drop(1))
            prefix[i] = prefix[i - 1] + num;
        for (const auto [i, num] : views::enumerate(nums))
            if (!num && prefix[i] == prefix[n - 1] - prefix[i]) ans += 2;
            else if (!num && abs(prefix[i] - prefix[n - 1] + prefix[i]) == 1) ans += 1;
        return ans;
    }
};