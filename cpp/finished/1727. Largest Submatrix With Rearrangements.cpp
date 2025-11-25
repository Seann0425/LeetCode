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
    int largestSubmatrix(vector<vector<int>> &matrix) {
        const auto m = matrix.size(), n = matrix[0].size();
        for (auto i = 1uz; i < m; i++)
            for (auto j = 0uz; j < n; j++)
                if (matrix[i][j]) matrix[i][j] += matrix[i - 1][j];
        auto ans = 0;
        for (auto i = 0uz; i < m; i++) {
            sort(matrix[i].begin(), matrix[i].end(), greater<int>());
            for (auto j = 0uz; j < n; j++) ans = max(ans, matrix[i][j] * static_cast<int>(j + 1));
        }
        return ans;
    }
};