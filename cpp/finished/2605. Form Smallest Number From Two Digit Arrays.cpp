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
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        vector<int> digit(10, 0);
        int num1 = INT_MAX, num2 = INT_MAX;
        for (const auto &i : nums1) {
            num1 = min(num1, i);
            digit[i]++;
        }
        for (const auto &i : nums2) {
            num2 = min(num2, i);
            digit[i]++;
        }
        for (int i = 1; i <= 9; i++)
            if (digit[i] == 2) return i;
        return 10 * min(num1, num2) + max(num1, num2);
    }
};