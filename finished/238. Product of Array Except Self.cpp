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
    vector<int> productExceptSelf(vector<int> &nums) {
        vector<int> products(nums.size(), 0);
        int zero_pos = -1, π = 1;
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            if (nums[i] == 0) {
                if (zero_pos != -1) return products;
                zero_pos = i;
                continue;
            }
            π *= nums[i];
        }
        if (zero_pos != -1) {
            products[zero_pos] = π;
            return products;
        }
        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            products[i] = π / nums[i];
        }
        return products;
    }
};