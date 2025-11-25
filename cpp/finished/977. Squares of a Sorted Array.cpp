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
    vector<int> sortedSquares(vector<int> &nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> square;
        int negative = 0, positive = 0;
        int n = nums.size();
        while (positive < n && nums[positive] < 0)
            positive++;
        while (negative < n - 1 && nums[negative + 1] < 0)
            negative++;
        if (positive == 0) {
            while (positive < n)
                square.push_back(pow(nums[positive++], 2));
            return square;
        } else if (negative == n - 1) {
            while (negative >= 0)
                square.push_back(pow(nums[negative--], 2));
            return square;
        } else {
            while (negative >= 0 || positive < n) {
                if (negative < 0) {
                    while (positive < n)
                        square.push_back(pow(nums[positive++], 2));
                    return square;
                } else if (positive == n) {
                    while (negative >= 0)
                        square.push_back(pow(nums[negative--], 2));
                    return square;
                } else {
                    if (abs(nums[positive]) < abs(nums[negative])) {
                        square.push_back(pow(nums[positive++], 2));
                    } else {
                        square.push_back(pow(nums[negative--], 2));
                    }
                }
            }
            return square;
        }
    }
};