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
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        array<array<int, 26>, 26> dist;

        // background
        for (auto &i : dist) i.fill(INT_MAX >> 1);
        for (size_t i = 0; i < 26; i++) dist[i][i] = 0;
        const auto path_count = cost.size();
        for (size_t i = 0; i < path_count; i++) {
            auto src = static_cast<size_t>(original[i] - 'a'), dst = static_cast<size_t>(changed[i] - 'a');
            dist[src][dst] = min(dist[src][dst], cost[i]);
        }

        // trivial floyd-warshall
        for (size_t k = 0; k < 26; k++) {
            for (size_t i = 0; i < 26; i++) {
                for (size_t j = 0; j < 26; j++) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }

        const auto n = source.size();
        long long ans = 0;
        for (size_t i = 0; i < n; i++) {
            auto src = static_cast<size_t>(source[i] - 'a'), dst = static_cast<size_t>(target[i] - 'a');
            if (dist[src][dst] == INT_MAX >> 1) return -1;
            ans += dist[src][dst];
        }

        return ans;
    }
};
