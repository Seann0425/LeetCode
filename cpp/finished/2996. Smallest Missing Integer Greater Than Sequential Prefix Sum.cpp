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
    int missingInteger(vector<int> &nums) {
        vector<int> prefixSum(nums.size());
        prefixSum[0] = nums[0];
        int sum = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1] + 1) {
                sum = prefixSum[i - 1];
                break;
            }
            prefixSum[i] = prefixSum[i - 1] + nums[i];
        }
        if (sum == 0) sum = prefixSum.back();
        unordered_set<int> exist;
        bool B = false;
        for (const auto &i : nums) {
            if (i == sum) B = true;
            exist.insert(i);
        }
        if (B == false) return sum;
        while (true) {
            sum++;
            if (!exist.count(sum)) return sum;
        }
        return -1;
    }
};