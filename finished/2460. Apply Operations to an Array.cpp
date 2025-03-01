#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    vector<int> applyOperations(vector<int> &nums) {
        const auto n = nums.size();
        for (auto i = 0uz; i < n - 1; ++i)
            if (nums[i] == nums[i + 1]) {
                nums[i] *= 2;
                nums[i + 1] = 0;
            }
        for (auto i = 0uz, j = 0uz; i < n; ++i) {
            if (j == n) nums[i] = 0;
            else {
                while (j < n and !nums[j]) ++j;
                nums[i] = j == n ? 0 : nums[j++];
            }
        }
        return nums;
    }
};