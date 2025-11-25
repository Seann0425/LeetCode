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
    vector<vector<int>> res;
    void backtrack(int k, int n, int num, vector<int> combination) {
        if (!n && !k) {
            res.push_back(combination);
            return;
        }
        if (num > 9 or !k or n < 0) return;
        backtrack(k, n, num + 1, combination);
        combination.push_back(num);
        backtrack(k - 1, n - num, num + 1, combination);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        if (n > 45 or (k * (19 - k) / 2) < n) return {};
        res.clear();
        backtrack(k, n, 1, {});
        return res;
    }
};