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
    int pair_n;
    vector<string> ans;
    void gen(string s, int unpaired, int left_count) {
        if (unpaired < 0) return;
        if (left_count == pair_n) {
            s.resize(pair_n << 1, ')');
            ans.push_back(s);
            return;
        }
        gen(s + '(', unpaired + 1, left_count + 1);
        gen(s + ')', unpaired - 1, left_count);
        return;
    }
public:
    vector<string> generateParenthesis(int n) {
        pair_n = n;
        gen(""s, 0, 0);
        return ans;
    }
};