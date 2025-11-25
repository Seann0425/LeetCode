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
    bool check_inside(size_t i, size_t j, size_t k, size_t l, const vector<vector<int>> &points) {
        for (auto x = 0uz; x < points.size(); x++) {
            if (x == i or x == j or x == k or x == l) continue;
            if (points[x][0] < points[i][0] or points[x][0] > points[k][0]) continue;
            if (points[x][1] > points[j][1] or points[x][1] < points[l][1]) continue;
            return true;
        }
        return false;
    }
public:
    int maxRectangleArea(vector<vector<int>> &points) {
        // given the constraints, just brute force
        const auto n = points.size();
        auto ans = -1;
        // i j
        // l k
        for (auto i = 0uz; i < n; i++) {
            for (auto j = 0uz; j < n; j++) {
                for (auto k = 0uz; k < n; k++) {
                    for (auto l = 0uz; l < n; l++) {
                        if (points[i][1] != points[j][1] or points[i][0] >= points[j][0]) continue;
                        if (points[j][0] != points[k][0] or points[j][1] <= points[k][1]) continue;
                        if (points[k][1] != points[l][1] or points[k][0] <= points[l][0]) continue;
                        if (points[l][0] != points[i][0] or points[i][1] <= points[l][1]) continue;
                        if (check_inside(i, j, k, l, points)) continue;
                        ans =
                            max(ans, (points[i][1] - points[l][1]) * (points[j][0] - points[i][0]));
                    }
                }
            }
        }
        return ans;
    }
};