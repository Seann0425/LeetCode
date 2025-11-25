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
    int findClosestNumber(vector<int> &nums) {
        // binary search
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";

        int left = 0, right = nums.size() - 1;
        while (right - left > 1) {
            int mid = (left + right) / 2;
            if (nums[mid] == 0) return nums[mid];
            else if (nums[mid] > 0) right = mid;
            else left = mid;
        }
        return ((abs(nums[left]) < abs(nums[right])) ? nums[left] : nums[right]);
    }
};