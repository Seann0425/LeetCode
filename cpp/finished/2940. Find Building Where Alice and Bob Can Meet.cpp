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
    vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries) {
        const auto n = heights.size(), m = queries.size();
        vector<int> ans(m, -1);
        vector<pair<int, int>> monotonic;
        vector<vector<pair<int, int>>> processed_queries(n);
        for (size_t i = 0; i < m; i++) {
            auto l = queries[i][0], r = queries[i][1];
            if (l > r) swap(l, r);
            if (heights[r] > heights[l] or l == r) ans[i] = r;
            else processed_queries[r].emplace_back(heights[l], i);
        }
        for (size_t i = n - 1; i < n; i--) {
            auto mono = monotonic.size();
            for (auto &[h, idx] : processed_queries[i]) {
                auto target =
                    upper_bound(monotonic.rbegin(), monotonic.rend(), h,
                                [](const auto &h, const auto &p) { return h < p.first; }) -
                    monotonic.rbegin() + 1;
                target = mono - target;
                if (target < mono) ans[idx] = monotonic[target].second;
            }
            while (!monotonic.empty() and monotonic.back().first <= heights[i])
                monotonic.pop_back();
            monotonic.emplace_back(heights[i], i);
        }
        return ans;
    }
};