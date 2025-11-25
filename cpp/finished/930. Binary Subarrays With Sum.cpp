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
    inline int sumToN(const int &n) {
        return n * (n + 1) / 2;
    }
public:
    int numSubarraysWithSum(vector<int> &nums, int goal) {
        int zero_count = 0;
        vector<int> zero_group;
        for (const auto &i : nums) {
            if (i == 1) {
                zero_group.push_back(zero_count);
                zero_count = 0;
            } else zero_count++;
        }
        zero_group.push_back(zero_count);

        int ans = 0;
        // sequence sum
        if (goal == 0) {
            for (const auto &group : zero_group)
                ans += sumToN(group);
        }
        // sliding window
        else {
            int left = 0, right = goal;
            for (; right < static_cast<int>(zero_group.size()); left++, right++) {
                ans += (zero_group[left] + 1) * (zero_group[right] + 1);
            }
        }
        return ans;
    }
};