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
    int minimumSubarrayLength(vector<int> &nums, int k) {
        vector<int> bitsCntr(32, 0);
        bitset<32> curNum{};
        size_t right = 0;
        int ans = INT_MAX;
        bool changed = false;
        for (const auto &i : nums) {
            if (i >= k) return 1;
        }
        for (size_t left = 0; left < nums.size(); left++) {
            while (right < nums.size() && static_cast<int>(curNum.to_ulong()) < k) {
                bitset<32> tmp(nums[right]);
                for (size_t i = 0; i < 32; i++) {
                    if (!tmp.test(i)) continue;
                    curNum.set(i);
                    bitsCntr[i]++;
                }
                right++;
            }
            if (static_cast<int>(curNum.to_ulong()) < k && right == nums.size()) break;
            if (static_cast<int>(right - left) < ans) {
                ans = static_cast<int>(right - left);
                changed = true;
            }
            bitset<32> tmp(nums[left]);
            for (size_t i = 0; i < 32; i++) {
                if (!tmp.test(i)) continue;
                bitsCntr[i]--;
                if (bitsCntr[i] <= 0) curNum.reset(i);
            }
        }
        return changed ? ans : -1;
    }
};