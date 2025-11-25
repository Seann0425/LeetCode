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

class Solution {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *cur = root;
        stack<TreeNode *> stk;
        stk.push(root);
        for (int i = 1; i < preorder.size(); i++) {
            if (cur->val > preorder[i]) {
                cur->left = new TreeNode(preorder[i]);
                stk.push(cur->left);
                cur = cur->left;
                continue;
            }
            while (!stk.empty() && stk.top()->val < preorder[i]) {
                cur = stk.top();
                stk.pop();
            }
            cur->right = new TreeNode(preorder[i]);
            stk.push(cur->right);
            cur = cur->right;
        }
        return root;
    }
};