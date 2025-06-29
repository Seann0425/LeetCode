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

#include <ranges>
class Solution {
public:
    vector<int> maxSubsequence(vector<int> &nums, size_t k) {
        const auto n = nums.size();
        vector<size_t> index(n);
        iota(index.begin(), index.end(), 0uz);

        sort(index.begin(), index.end(), [&](const auto &a, const auto &b) {
            return nums[a] > nums[b];
        });
        sort(index.begin(), index.begin() + k);
        vector<int> ans;
        ans.reserve(k);
        for (const auto &i : index | views::take(k))
    }
};