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
    using Coordinate = pair<int, int>;
    static constexpr array<int, 5> direction{0, 1, 0, -1, 0};
public:
    // the distance to the nearest one
    vector<vector<int>> highestPeak(vector<vector<int>> &is_water) {
        const auto m = is_water.size(), n = is_water[0].size();
        vector<vector<int>> ans(m, vector<int>(n, -1));
        queue<Coordinate> bfs;
        for (auto i = 0uz; i < m; i++)
            for (auto j = 0uz; j < n; j++)
                if (is_water[i][j]) {
                    ans[i][j] = 0;
                    bfs.emplace(i, j);
                }

        while (!bfs.empty()) {
            const auto [x, y] = bfs.front();
            bfs.pop();
            for (auto at = 0uz; at < 4uz; at++) {
                auto new_x = x + direction[at], new_y = y + direction[at + 1];
                if (new_x >= m or new_y >= n or ans[new_x][new_y] != -1) continue;
                ans[new_x][new_y] = ans[x][y] + 1;
                bfs.emplace(new_x, new_y);
            }
        }
        return ans;
    }
};