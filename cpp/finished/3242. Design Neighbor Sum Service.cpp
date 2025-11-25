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

class NeighborSum {
    constexpr static array<int, 5> direc{0, 1, 0, -1, 0};
    constexpr static array<int, 5> diag{1, 1, -1, -1, 1};
    vector<vector<int>> grid;
    array<int, 100> pos;
    int n;
public:
    NeighborSum(vector<vector<int>> &grid) {
        this->n = grid.size();
        this->grid.resize(n, vector<int>(n));
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < n; j++) {
                this->grid[i][j] = grid[i][j];
                pos[grid[i][j]] = i * n + j;
            }
        }
    }

    int adjacentSum(int value) {
        auto x = pos[value] / n, y = pos[value] % n;
        auto ans = 0;
        for (size_t at = 0; at < 4; at++) {
            auto nx = x + direc[at], ny = y + direc[at + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) ans += grid[nx][ny];
        }
        return ans;
    }

    int diagonalSum(int value) {
        auto x = pos[value] / n, y = pos[value] % n;
        auto ans = 0;
        for (size_t at = 0; at < 4; at++) {
            auto nx = x + diag[at], ny = y + diag[at + 1];
            if (nx >= 0 && nx < n && ny >= 0 && ny < n) ans += grid[nx][ny];
        }
        return ans;
    }
};