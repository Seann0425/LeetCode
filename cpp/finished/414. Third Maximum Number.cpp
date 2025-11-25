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
    int thirdMax(vector<int> &nums) {
        int first, second, third;
        int minimum = INT_MAX;
        int n = nums.size();
        first = second = third = INT_MIN;
        for (int i = 0; i < n; i++)
            if (nums[i] > first) first = nums[i];
        for (int i = 0; i < n; i++)
            if (nums[i] > second && nums[i] < first) second = nums[i];
        for (int i = 0; i < n; i++) {
            if (nums[i] > third && nums[i] < second) third = nums[i];
            if (nums[i] < minimum) minimum = nums[i];
        }
        return (second == INT_MIN || (third == INT_MIN && minimum != INT_MIN)) ? first : third;
    }
};