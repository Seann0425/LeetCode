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
    size_t n;
    void backtracking(vector<vector<int>> &combinations, vector<int> &cur, size_t i, int target,
                      vector<int> &candidates) {
        if (i == n || target < 0) return;
        if (target == 0) {
            combinations.push_back(cur);
            return;
        }
        int next_num = 1;
        while (i + next_num < n and candidates[next_num + i] == candidates[i]) next_num++;
        backtracking(combinations, cur, i + next_num, target, candidates);
        for (int j = 1; j <= next_num; j++) {
            cur.push_back(candidates[i]);
            backtracking(combinations, cur, i + next_num, target - candidates[i] * j, candidates);
        }
        for (int j = 0; j < next_num; j++) cur.pop_back();
    }
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
        n = candidates.size();
        vector<int> cur;
        vector<vector<int>> combinations;
        sort(candidates.begin(), candidates.end());
        backtracking(combinations, cur, 0, target, candidates);
        return combinations;
    }
};