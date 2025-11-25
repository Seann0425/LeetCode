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
    string convert(string s, size_t num_rows) {
        if (num_rows == 1) return s;
        const auto n = s.size();
        string ans{};
        auto period = 2 * (num_rows - 1);
        // first row
        for (size_t i = 0; i < n; i += period) ans += s[i];
        // middle rows
        for (size_t row = 1; row < num_rows - 1; row++) {
            for (size_t i = row; i < n; i += period) {
                ans += s[i];
                if (i + 2 * (num_rows - 1 - row) < n) ans += s[i + 2 * (num_rows - 1 - row)];
            }
        }
        // last row
        for (size_t i = num_rows - 1; i < n; i += period) ans += s[i];
        return ans;
    }
};