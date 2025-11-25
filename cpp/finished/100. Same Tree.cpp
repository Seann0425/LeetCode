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
    bool isSameTree(TreeNode *p, TreeNode *q) {
        stack<TreeNode *> ptodo;
        stack<TreeNode *> qtodo;
        TreeNode *pcur = p;
        TreeNode *qcur = q;
        while (pcur != nullptr || !ptodo.empty()) {
            while (pcur != nullptr) {
                if (qcur == nullptr) return false;
                if (pcur->val != qcur->val) return false;
                ptodo.push(pcur);
                qtodo.push(qcur);
                pcur = pcur->left;
                qcur = qcur->left;
            }
            if (qcur != nullptr) return false;
            pcur = ptodo.top()->right;
            qcur = qtodo.top()->right;
            ptodo.pop();
            qtodo.pop();
        }
        if (pcur == nullptr && qcur != nullptr) return false;
        return true;
    }
};