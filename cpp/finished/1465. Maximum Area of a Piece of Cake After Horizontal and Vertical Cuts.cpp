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
    constexpr static int MOD = 1e9 + 7;
public:
    int maxArea(int h, int w, vector<int> &horizontal_cuts, vector<int> &vertical_cuts) {
        sort(horizontal_cuts.begin(), horizontal_cuts.end());
        sort(vertical_cuts.begin(), vertical_cuts.end());
        auto h_cut = horizontal_cuts.front(), v_cut = vertical_cuts.front();
        const auto n = horizontal_cuts.size(), m = vertical_cuts.size();
        horizontal_cuts.push_back(h);
        vertical_cuts.push_back(w);
        for (auto i = 1uz; i <= n; i++)
            h_cut = max(h_cut, horizontal_cuts[i] - horizontal_cuts[i - 1]);
        for (auto i = 1uz; i <= m; i++) v_cut = max(v_cut, vertical_cuts[i] - vertical_cuts[i - 1]);
        return (static_cast<long long>(h_cut) % MOD) * (static_cast<long long>(v_cut) % MOD) % MOD;
    }
};