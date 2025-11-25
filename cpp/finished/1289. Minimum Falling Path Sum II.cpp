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

inline void findMinimum(pair<int, size_t> &minimum1, pair<int, size_t> &minimum2, int candidate, size_t pos) {
    if (candidate < minimum1.first) {
        swap(minimum1, minimum2);
        minimum1.first = candidate;
        minimum1.second = pos;
    } else if (candidate < minimum2.first) {
        minimum2.first = candidate;
        minimum2.second = pos;
    }
}

class Solution {
public:
    int minFallingPathSum(vector<vector<int>> &grid) {
        auto N = grid.size();
        vector<vector<int>> fallingCost(N, vector<int>(N));
        pair<int, size_t> minimum1{INT_MAX, numeric_limits<size_t>::max()}, minimum2{INT_MAX, numeric_limits<size_t>::max()};
        // initial step
        for (size_t i = 0; i < N; i++) {
            fallingCost.front()[i] = grid.front()[i];
            findMinimum(minimum1, minimum2, fallingCost.front()[i], i);
        }
        // recursive
        for (size_t i = 1; i < N; i++) {
            pair<int, size_t> tmp1{INT_MAX, numeric_limits<size_t>::max()}, tmp2{INT_MAX, numeric_limits<size_t>::max()};
            for (size_t j = 0; j < N; j++) {
                if (j != minimum1.second) {
                    fallingCost[i][j] = minimum1.first + grid[i][j];
                } else fallingCost[i][j] = minimum2.first + grid[i][j];
                findMinimum(tmp1, tmp2, fallingCost[i][j], j);
            }
            swap(minimum1, tmp1);
            swap(minimum2, tmp2);
        }
        return *min_element(fallingCost.back().begin(), fallingCost.back().end());
    }
};