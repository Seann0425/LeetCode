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
    vector<string> summaryRanges(vector<int> &nums) {
        vector<string> rangeSet;
        if (!nums.size()) return rangeSet;
        if (nums.size() == 1) {
            rangeSet.push_back(to_string(nums[0]));
            return rangeSet;
        }
        int prev = 0;
        int curr = 1;
        while (curr != nums.size()) {
            if ((long)nums[curr] - nums[curr - 1] > 1) {
                string input = to_string(nums[prev]);
                if (prev != curr - 1) {
                    input = input + "->";
                    input = input + to_string(nums[curr - 1]);
                }
                rangeSet.push_back(input);
                prev = curr;
            }
            curr++;
        }
        string temp = to_string(nums[prev]);
        if (prev != nums.size() - 1) {
            temp = temp + "->";
            temp = temp + to_string(nums[nums.size() - 1]);
        }
        rangeSet.push_back(temp);
        return rangeSet;
    }
};