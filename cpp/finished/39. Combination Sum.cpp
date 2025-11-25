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
        cur.push_back(candidates[i]);
        backtracking(combinations, cur, i, target - candidates[i], candidates);
        cur.pop_back();
        backtracking(combinations, cur, i + 1, target, candidates);
    }
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
        n = candidates.size();
        vector<int> cur;
        vector<vector<int>> combinations;
        backtracking(combinations, cur, 0, target, candidates);
        return combinations;
    }
};

// constexpr size_t max_n = 45;

// class Solution {
//     bitset<max_n> exist_num;
//     void destruct(const vector<int> &prev, vector<vector<int>> &combinations, int target,
//                   size_t maximum) {
//         if (!target) combinations.push_back(prev);
//         if (target <= 0) return;

//         for (size_t i = maximum; i < max_n; i++)
//             if (exist_num[i]) {
//                 vector<int> cur(prev);
//                 cur.push_back(i);
//                 destruct(cur, combinations, target - i, i);
//             }
//     }
// public:
//     vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
//         for (const auto &i : candidates) exist_num.set(static_cast<size_t>(i));
//         vector<vector<int>> combinations;
//         destruct({}, combinations, target, 0);
//         return combinations;
//     }
// };