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
    int minDeletionSize(vector<string> &strs) {
        const auto n = strs.size(), m = strs[0].size();
        auto ans = 0;
        vector<bool> sorted(n - 1, false);
        for (auto j = 0; j < m; j++) {
            bool deleted = false;
            for (auto i = 0; i < n - 1; i++)
                if (!sorted[i] and strs[i][j] > strs[i + 1][j]) {
                    ans++;
                    deleted = true;
                    break;
                }

            if (deleted) continue;
            for (auto i = 0; i < n - 1; i++)
                if (strs[i][j] < strs[i + 1][j]) sorted[i] = true;
        }
        return ans;
    }
};