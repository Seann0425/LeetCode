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

/*the solution should start from below*/

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        const auto N = matrix.size();
        for (size_t i = 0; i < N; i++) {
            for (size_t j = i + 1; j < N; j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        for (auto &i : matrix)
            reverse(i.begin(), i.end());
    }
};