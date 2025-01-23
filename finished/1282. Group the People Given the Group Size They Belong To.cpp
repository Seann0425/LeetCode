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
    vector<vector<int>> groupThePeople(vector<int> &group_sizes) {
        const auto n = group_sizes.size();
        array<size_t, 505> size2group;
        size2group.fill(numeric_limits<size_t>::max());
        vector<vector<int>> ans;
        for (auto i = 0uz; i < n; i++) {
            if (size2group[group_sizes[i]] == numeric_limits<size_t>::max()) {
                size2group[group_sizes[i]] = ans.size();
                ans.push_back(vector<int>());
            }
            ans[size2group[group_sizes[i]]].push_back(i);
            if (ans[size2group[group_sizes[i]]].size() == group_sizes[i])
                size2group[group_sizes[i]] = numeric_limits<size_t>::max();
        }
        return ans;
    }
};