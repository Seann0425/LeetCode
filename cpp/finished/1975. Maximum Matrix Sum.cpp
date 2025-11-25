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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>> &matrix) {
        // consider the adjacent element to be flipped
        // if both of them are positive, there's no need to flip
        // if both of them are negative, flip the pair is always an optimal choice
        // if only one of them is negative, flip the pair is like moving the negative sign
        // the goal is to move the negative sign to the element with the smallest absolute value
        // and eliminate other negative signs
        auto abs_sum = 0ll;
        auto negative_count = 0, min_abs = numeric_limits<int>::max();
        const auto n = matrix.size();
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                abs_sum += abs(matrix[i][j]);
                min_abs = min(min_abs, abs(matrix[i][j]));
                negative_count += (matrix[i][j] < 0);
            }
        }
        return negative_count % 2 ? abs_sum - 2 * min_abs : abs_sum;
    }
};