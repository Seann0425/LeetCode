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

/*the solution should start from below*/

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> maximum(nums.size());
        vector<int> endMaximum(nums.size());

        maximum[0] = nums[0];
        endMaximum[0] = nums[0];

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > endMaximum[i - 1] + nums[i]) endMaximum[i] = nums[i];
            else endMaximum[i] = endMaximum[i - 1] + nums[i];

            if (endMaximum[i] > maximum[i - 1]) maximum[i] = endMaximum[i];
            else maximum[i] = maximum[i - 1];
        }

        return maximum.back();
    }
};