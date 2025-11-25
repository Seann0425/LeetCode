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
    vector<vector<int>> is_connected;

    auto check_connected(vector<vector<int>> &languages, size_t u, size_t v) -> int {
        if (is_connected[u][v]) return is_connected[u][v];
        const auto n = languages[u].size();
        for (auto i = 0uz; i < n; i++)
            if (binary_search(languages[v].begin(), languages[v].end(), languages[u][i]))
                return is_connected[u][v] = is_connected[v][u] = 1;
        return is_connected[u][v] = is_connected[v][u] = -1;
    }
public:
    int minimumTeachings(size_t n, vector<vector<int>> &languages,
                         vector<vector<int>> &friendships) {
        const auto m = languages.size();
        auto ans = numeric_limits<int>::max();
        is_connected.assign(m + 1, vector<int>(m + 1, 0));
        for (auto &l : languages) sort(l.begin(), l.end());
        for (auto l = 1uz; l <= n; l++) {
            auto count = 0;
            vector<bool> teach(m, false);
            for (const auto &f : friendships) {
                const auto u = f[0] - 1, v = f[1] - 1;
                if (check_connected(languages, u, v) == 1) continue;
                if (!binary_search(languages[u].begin(), languages[u].end(), l)) {
                    if (!teach[u]) count++;
                    teach[u] = true;
                }
                if (!binary_search(languages[v].begin(), languages[v].end(), l)) {
                    if (!teach[v]) count++;
                    teach[v] = true;
                }
            }
            if (!count) return 0;
            ans = min(ans, count);
        }
        return ans;
    }
};