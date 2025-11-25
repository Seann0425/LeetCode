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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int minOperations(vector<vector<int>> &grid, int x) {
        const auto m = grid.size(), n = grid[0].size();
        vector<int> compressed;
        compressed.reserve(m * n);
        for (const auto &row : grid) {
            for (const auto &i : row) {
                if ((i - grid[0][0]) % x) return -1;
                compressed.push_back(i);
            }
        }
        const auto len = compressed.size();
        sort(compressed.begin(), compressed.end());
        auto prefix_index = 0uz, suffix_index = len - 1;
        auto ans = 0;
        while (prefix_index < suffix_index) {
            if (prefix_index < len - 1 - suffix_index) {
                ans += (compressed[prefix_index + 1] - compressed[prefix_index]) / x *
                       (prefix_index + 1);
                ++prefix_index;
            } else {
                ans += (compressed[suffix_index] - compressed[suffix_index - 1]) / x *
                       (len - suffix_index);
                --suffix_index;
            }
        }
        return ans;
    }
};