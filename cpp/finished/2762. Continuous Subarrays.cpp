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
    long long continuousSubarrays(vector<int> &nums) {
        const auto N = nums.size();
        deque<size_t> increasing, decreasing;
        size_t right = 0;
        long long cntr = 0;
        for (size_t left = 0; left < N; left++) {
            while (right < N && (increasing.empty() || nums[decreasing.front()] - nums[right] <= 2 && nums[right] - nums[increasing.front()] <= 2)) {
                while (!decreasing.empty() && nums[decreasing.back()] < nums[right])
                    decreasing.pop_back();
                decreasing.push_back(right);
                while (!increasing.empty() && nums[increasing.back()] > nums[right])
                    increasing.pop_back();
                increasing.push_back(right);
                right++;
            }
            cntr += static_cast<long long>(right - left);
            while (!decreasing.empty() && decreasing.front() <= left)
                decreasing.pop_front();
            while (!increasing.empty() && increasing.front() <= left)
                increasing.pop_front();
        }
        return cntr;
    }
};