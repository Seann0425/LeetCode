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
    int countServers(vector<vector<int>> &grid) {
        const auto m = grid.size(), n = grid[0].size();
        vector<int> row(m), col(n);
        for (auto i = 0uz; i < m; i++)
            for (auto j = 0uz; j < n; j++)
                if (grid[i][j]) row[i]++, col[j]++;
        auto ans = 0;
        for (auto i = 0uz; i < m; i++)
            for (auto j = 0uz; j < n; j++)
                if (grid[i][j] and (row[i] > 1 or col[j] > 1)) ans++;
        return ans;
    }
};