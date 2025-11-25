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
    vector<int> rearrangeArray(vector<int> &nums) {
        vector<int> ans;
        int positive = 0, negative = 0;
        int cnt = 0;

        while (cnt < nums.size()) {
            // positive
            if (cnt % 2 == 0) {
                while (nums[positive] < 0)
                    positive++;
                ans.push_back(nums[positive++]);
                cnt++;
            }
            // negative
            else {
                while (nums[negative] > 0)
                    negative++;
                ans.push_back(nums[negative++]);
                cnt++;
            }
        }

        return ans;
    }
};