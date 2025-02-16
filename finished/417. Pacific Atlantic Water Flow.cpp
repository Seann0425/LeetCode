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
    size_t m, n;
    constexpr static array<int, 5> dir{0, 1, 0, -1, 0};
    void dfs(const vector<vector<int>> &heights, vector<vector<bool>> &visited, size_t i,
             size_t j) {
        visited[i][j] = true;
        for (auto k = 0; k < 4; k++) {
            auto x = i + dir[k], y = j + dir[k + 1];
            if (x >= m or y >= n or visited[x][y] or heights[x][y] < heights[i][j]) continue;
            dfs(heights, visited, x, y);
        }
    }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
        m = heights.size(), n = heights[0].size();
        vector pacific(m, vector<bool>(n, false)), atlantic(m, vector<bool>(n, false));

        for (auto i = 0uz; i < m; i++) {
            dfs(heights, pacific, i, 0);
            dfs(heights, atlantic, i, n - 1);
        }
        for (auto i = 0uz; i < n; i++) {
            dfs(heights, pacific, 0, i);
            dfs(heights, atlantic, m - 1, i);
        }

        vector<vector<int>> ans;
        for (auto i = 0; i < m; i++)
            for (auto j = 0; j < n; j++)
                if (pacific[i][j] and atlantic[i][j]) ans.push_back({i, j});

        return ans;
    }
};