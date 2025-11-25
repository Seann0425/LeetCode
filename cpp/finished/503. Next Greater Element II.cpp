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
    vector<int> nextGreaterElements(vector<int> &nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // monotonic stack practice
        vector<int> res(nums.size(), -1);
        stack<int> stk;

        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() < nums[i])
                stk.pop();
            stk.push(nums[i]);
        }

        // find the greatest element
        for (int i = nums.size() - 1; i >= 0; i--) {
            while (!stk.empty() && stk.top() <= nums[i])
                stk.pop();
            if (!stk.empty()) res[i] = stk.top();
            stk.push(nums[i]);
        }
        return res;
    }
};