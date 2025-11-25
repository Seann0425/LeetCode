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
    int getCommon(vector<int> &nums1, vector<int> &nums2) {
        int ptr1 = 0, ptr2 = 0;
        const int n1 = static_cast<int>(nums1.size()), n2 = static_cast<int>(nums2.size());
        while (ptr1 < n1 && ptr2 < n2) {
            if (nums1[ptr1] > nums2[ptr2]) ptr2++;
            else if (nums1[ptr1] < nums2[ptr2]) ptr1++;
            else return nums1[ptr1];
        }
        return -1;
    }
};