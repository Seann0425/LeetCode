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
    const static int VISITED = numeric_limits<int>::max();
    array<int, 5> direc{0, 1, 0, -1, 0};
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix) {
        const auto m = matrix.size(), n = matrix[0].size();
        const auto total_len = m * n;
        vector<int> ans;
        ans.reserve(total_len);
        auto x = 0uz, y = 0uz, at = 0uz;
        while (ans.size() < total_len) {
            ans.push_back(matrix[x][y]);
            matrix[x][y] = VISITED;
            auto nx = x + direc[at], ny = y + direc[at + 1];
            if (nx >= m or ny >= n or matrix[nx][ny] == VISITED) at = (at + 1) % 4;
            x += direc[at];
            y += direc[at + 1];
        }
        return ans;
    }
};