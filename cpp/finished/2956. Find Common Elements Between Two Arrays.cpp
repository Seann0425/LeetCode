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
    vector<int> findIntersectionValues(vector<int> &nums1, vector<int> &nums2) {
        unordered_map<int, bool> cnt1, cnt2;
        for (const auto &i : nums1)
            cnt1[i] = true;
        for (const auto &i : nums2)
            cnt2[i] = true;
        for (const auto &i : nums1)
            if (cnt2.count(i)) cnt2[i] = false;
        for (const auto &i : nums2)
            if (cnt1.count(i)) cnt1[i] = false;
        vector<int> ans(2, 0);
        for (int i = 0; i < nums1.size(); i++) {
            if (cnt1[nums1[i]] == false) ans[0]++;
        }
        for (int i = 0; i < nums2.size(); i++) {
            if (cnt2[nums2[i]] == false) ans[1]++;
        }
        return ans;
    }
};