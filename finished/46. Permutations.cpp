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
    vector<vector<int>> permute(vector<int> &nums) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        do ans.push_back(nums);
        while (next_permutation(nums.begin(), nums.end()));
        return ans;
    }
};

class Solution {
    size_t n;
    vector<bool> picked;
    vector<int> path;
    vector<vector<int>> ans;
    void backtrack(size_t index, vector<int> &nums) {
        if (index == n) {
            ans.push_back(path);
            return;
        }
        for (size_t i = 0; i < n; i++) {
            if (picked[i]) continue;
            picked[i] = true;
            path.push_back(nums[i]);
            backtrack(index + 1, nums);
            picked[i] = false;
            path.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int> &nums) {
        n = nums.size();
        picked.resize(n, false);
        path.reserve(n);
        backtrack(0uz, nums);
        return ans;
    }
};