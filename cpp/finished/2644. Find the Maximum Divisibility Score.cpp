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
    int maxDivScore(vector<int> &nums, vector<int> &divisors) {
        // brute force
        int ans, maxCnt = -1;
        for (const auto &d : divisors) {
            int cnt = 0;
            for (const auto &n : nums) {
                if (n % d == 0) cnt++;
            }
            if (cnt > maxCnt) {
                maxCnt = cnt;
                ans = d;
            } else if (cnt == maxCnt && d < ans) {
                ans = d;
            }
        }
        return ans;
    }
};