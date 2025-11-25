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
    int numSubarrayProductLessThanK(vector<int> &nums, int k) {
        if (k == 0) return 0;
        const auto n = nums.size();
        nums.push_back(INT_MAX);

        size_t right = 0;
        long long product = 1, tmp;
        int ans = 0;
        for (size_t left = 0; left < n; left++, right = max(left, right)) {
            // right = max(left, right) => in case nums[left] itlsef is not strictly less than k
            if (right != n) {
                while ((tmp = product * nums[right++]) < k)
                    product = tmp;
                right--; // right is incremented one more time at nums[right++]
            }
            ans += right - left;
            if (right != left) product /= nums[left];
        }
        return ans;
    }
};