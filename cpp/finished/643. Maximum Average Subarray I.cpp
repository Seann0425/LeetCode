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
    double findMaxAverage(vector<int> &nums, int k) {
        ios_base::sync_with_stdio(0);
        if (nums.size() == 1) return (double)nums[0];
        int left = 0, right = k - 1;
        double mx, cur = 0;
        for (int i = 0; i < k; i++)
            cur += nums[i];
        mx = cur;
        while (right < nums.size() - 1) {
            cur -= nums[left];
            left++;
            right++;
            cur += nums[right];
            mx = max(mx, cur);
        }
        return mx / k;
    }
};