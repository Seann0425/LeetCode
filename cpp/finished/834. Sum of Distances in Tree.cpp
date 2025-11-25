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
// #pragma GCC optimize("O3", "unroll-loops")
// static const auto __ = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
    vector<int> height, descendent, ans;
    vector<vector<size_t>> adj_list;
    int dfs(size_t node) {
        int descendent_count = 1; // include the node itself
        for (const auto &adj : adj_list[node]) {
            if (height[adj] == -1) {
                height[adj] = height[node] + 1;
                ans[adj] = ans[node] + static_cast<int>(adj_list.size()) - 2 * descendent[adj];
                descendent_count += dfs(adj);
            }
        }
        descendent[node] = descendent_count;
        return descendent_count;
    }
public:
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>> &edges) {
        const auto N = edges.size() + 1;
        height.resize(N, -1);
        descendent.resize(N);
        ans.resize(N, 0);
        adj_list.resize(N);
        for (const auto &edge : edges) {
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }

        // initial step for ans
        // build descendent
        height[0] = 0;
        dfs(0);
        ans[0] = accumulate(height.begin(), height.end(), 0);
        fill(height.begin(), height.end(), -1);

        // dp
        height[0] = 0;
        dfs(0);

        return ans;
    }
};