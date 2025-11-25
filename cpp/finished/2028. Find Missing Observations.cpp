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
    vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
        int m = static_cast<int>(rolls.size()), sum = mean * (m + n);
        int known_sum = reduce(rolls.begin(), rolls.end()), unknown_sum = sum - known_sum;
        if (unknown_sum > n * 6 || unknown_sum < n) return {};

        vector<int> missing(n, 1);
        auto six_count = (unknown_sum - n) / 5;
        fill(missing.begin(), missing.begin() + six_count, 6);
        if (six_count < n) missing[static_cast<size_t>(six_count)] += (unknown_sum - n) % 5;

        return missing;
    }
};