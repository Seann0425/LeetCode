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
    int maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
        const auto n = matrix[0].size();
        unordered_map<bitset<300>, int> mp;
        for (const auto &row : matrix) {
            bitset<300> tmp;
            if (row.front())
                for (size_t i = 0; i < n; i++) tmp[i] = !row[i];
            else
                for (size_t i = 0; i < n; i++) tmp[i] = row[i];
            mp[tmp]++;
        }
        return max_element(mp.begin(), mp.end(),
                           [](const auto &a, const auto &b) { return a.second < b.second; })
            ->second;
    }
};