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
    int specialArray(vector<int> &nums) {
        /*proof that if the array is special, than the value for x is unique:
        suppose that there exist two different value for x, a and b, respectively
        since b doesn't equal to a, it must be greater or less than a
        if it's greater than a, then the numbers that are greater than b will be less than the numbers that are greater than a, which contradict the
        assumption that b is a value of x similarly, contradiction also happens when b is less than a therefore b must equals to a, which means that
        the value for x is unique*/
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] >= n - i) {
                if (i == 0) return n - i;
                if (nums[i - 1] < n - i) return n - i;
            }
        }
        return -1;
    }
};