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
    int findIDX(vector<int> &nums, int start, int end) {
        return max_element(nums.begin() + start, nums.begin() + end + 1) - nums.begin();
    }

    void buildTree(vector<int> &nums, int start, int end, TreeNode **root) {
        if (end < start) return;
        *root = new TreeNode();
        if (start == end) {
            (*root)->val = nums[start];
            return;
        }
        int cur = findIDX(nums, start, end);
        (*root)->val = nums[cur];
        buildTree(nums, start, cur - 1, &((*root)->left));
        buildTree(nums, cur + 1, end, &((*root)->right));
        return;
    }
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        TreeNode *root;
        buildTree(nums, 0, nums.size() - 1, &root);
        return root;
    }
};