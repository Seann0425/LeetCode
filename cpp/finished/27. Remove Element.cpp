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
    int removeElement(vector<int> &nums, int val) {
        if (nums.empty()) return 0;
        for (int i = 0; i <= nums.size() - 1; i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
                if (nums.empty()) return 0;
            }
        }
        return nums.size();
    }
};