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
    int largestSumAfterKNegations(vector<int> &nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int negCount = 0;
        while (nums[negCount] < 0 && k) {
            nums.push_back(abs(nums[negCount++]));
            k--;
        }
        cout << nums.back() << endl;
        if (k % 2) {
            if (nums.back() < nums[negCount]) nums.back() *= (-1);
            else nums.push_back((-1) * nums[negCount]);
        }
        return accumulate(nums.end() - n, nums.end(), 0);
    }
};