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
    static const int N = 1e5 + 5;
public:
    int firstMissingPositive(vector<int> &nums) {
        for (auto &i : nums) {
            if (i <= 0) i = N;
        }
        for (const auto &i : nums) {
            if (abs(i) > nums.size()) continue;
            if (nums[abs(i) - 1] > 0) nums[abs(i) - 1] *= (-1);
        }
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) return i + 1;
        }
        return nums.size() + 1;
    }
};