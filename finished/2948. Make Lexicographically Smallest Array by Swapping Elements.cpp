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
    vector<int> lexicographicallySmallestArray(vector<int> &nums, int limit) {
        vector<int> sorted_nums(nums);
        sort(sorted_nums.begin(), sorted_nums.end());

        unordered_map<int, int> group_index;
        vector<list<int>> groups;
        const auto n = nums.size();
        for (auto i = 0uz, g = 0uz; i < n; i++) {
            if (i and sorted_nums[i] - sorted_nums[i - 1] > limit) g++;
            group_index[sorted_nums[i]] = g;
            if (g == groups.size()) groups.emplace_back();
            groups[g].push_back(sorted_nums[i]);
        }
        for (auto &i : nums) {
            i = groups[group_index[i]].front();
            groups[group_index[i]].pop_front();
        }
        return nums;
    }
};