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

/*the solution should start from below*/

class Solution {
    void backtracking(int idx, vector<int> chosen, vector<vector<int>> &combinitions, int k, int n) {
        if (chosen.size() == k) {
            combinitions.push_back(chosen);
            return;
        } else if (idx == n + 1) return;
        if (chosen.size() + (n - idx + 1) < k) return;
        backtracking(idx + 1, chosen, combinitions, k, n);
        chosen.push_back(idx);
        backtracking(idx + 1, chosen, combinitions, k, n);
        return;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> combinitions;
        backtracking(1, vector<int>(), combinitions, k, n);
        return combinitions;
    }
};