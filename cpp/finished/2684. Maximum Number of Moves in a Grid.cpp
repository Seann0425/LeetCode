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
    int maxMoves(vector<vector<int>> &grid) {
        const auto m = grid.size(), n = grid.front().size();
        auto ans = 0;
        vector<vector<int>> dp_transpose(n, vector<int>(m, 0));
        for (size_t col = 1; col < n; col++) {
            for (size_t row = 0; row < m; row++) {
                // check three previous cell
                for (int i = -1; i <= 1; i++) {
                    if (row + i >= m || grid[row][col] <= grid[row + i][col - 1]) continue;
                    // start from first cell
                    if (dp_transpose[col - 1][row + i] < col - 1) continue;
                    dp_transpose[col][row] =
                        max(dp_transpose[col - 1][row + i] + 1, dp_transpose[col][row]);
                    ans = max(ans, dp_transpose[col][row]);
                }
            }
        }
        return ans;
    }
};