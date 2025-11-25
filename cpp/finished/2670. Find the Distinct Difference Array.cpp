#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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

class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int> &nums) {
        unordered_map<int, int> right;
        unordered_set<int> left;
        for (const auto &i : nums)
            right[i]++;
        int rightDistinct = right.size();
        vector<int> ans(nums.size());
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            left.insert(nums[i]);
            right[nums[i]]--;
            if (right[nums[i]] == 0) rightDistinct--;
            ans[i] = static_cast<int>(left.size()) - rightDistinct;
        }
        return ans;
    }
};