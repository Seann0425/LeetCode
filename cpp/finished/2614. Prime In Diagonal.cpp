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
    bool isPrime(int n) {
        if (n == 1) return false;
        for (int i = 2; i <= static_cast<int>(sqrt(n)); i++) {
            if (n % i == 0) return false;
        }
        return true;
    }
public:
    int diagonalPrime(vector<vector<int>> &nums) {
        const int n = nums.size();
        int maximum = 0;
        for (int i = 0; i < n; i++) {
            if (isPrime(nums[i][i])) maximum = max(maximum, nums[i][i]);
            if (isPrime(nums[i][n - i - 1])) maximum = max(maximum, nums[i][n - i - 1]);
        }
        return maximum;
    }
};