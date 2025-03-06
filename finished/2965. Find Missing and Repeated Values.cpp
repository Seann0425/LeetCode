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
    vector<int> findMissingAndRepeatedValues(vector<vector<int>> &grid) {
        const auto n = static_cast<long long>(grid.size() * grid.size());
        auto sum = 0ll, sqr_sum = 0ll;
        for (const auto &row : grid) {
            for (const auto &x : row) {
                sum += x;
                sqr_sum += static_cast<long long>(x) * x;
            }
        }
        auto sum_diff = sum - n * (n + 1) / 2;
        auto sqr_sum_diff = sqr_sum - n * (n + 1) * (2 * n + 1) / 6;
        auto repeated = static_cast<int>((sqr_sum_diff / sum_diff + sum_diff) / 2);
        auto missing = static_cast<int>((sqr_sum_diff / sum_diff - sum_diff) / 2);
        return {repeated, missing};
    }
};