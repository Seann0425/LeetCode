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
    enum Status : int { UNKNOWN = 0, INCREASING = 1, DECREASING = -1 };
public:
    bool isMonotonic(vector<int> &nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        Status status = UNKNOWN;
        for (int i = 1; i < nums.size(); i++) {
            switch (status) {
            case INCREASING:
                if (nums[i] < nums[i - 1]) return false;
                break;
            case DECREASING:
                if (nums[i] > nums[i - 1]) return false;
                break;
            default:
                if (nums[i] > nums[i - 1]) status = INCREASING;
                else if (nums[i] < nums[i - 1]) status = DECREASING;
                break;
            }
        }
        return true;
    }
};