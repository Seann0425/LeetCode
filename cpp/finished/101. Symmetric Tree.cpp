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
public:
    bool isSymmetric(TreeNode *root) {
        TreeNode *L = root->left;
        TreeNode *R = root->right;
        stack<TreeNode *> Ltodo;
        stack<TreeNode *> Rtodo;
        while (L != nullptr || !Ltodo.empty()) {
            while (L != nullptr) {
                if (R == nullptr) return false;
                if (L->val != R->val) return false;
                Ltodo.push(L);
                Rtodo.push(R);
                L = L->left;
                R = R->right;
            }
            if (R != nullptr) return false;
            L = Ltodo.top()->right;
            R = Rtodo.top()->left;
            Ltodo.pop();
            Rtodo.pop();
        }
        if (L == nullptr && R != nullptr) return false;
        return true;
    }
};