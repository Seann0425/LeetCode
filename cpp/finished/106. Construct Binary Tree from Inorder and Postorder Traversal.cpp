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
private:
    void createMapping(const vector<int> &inorder, unordered_map<int, int> &nodeToIdx, int n) {
        for (int i = 0; i < n; i++)
            nodeToIdx[inorder[i]] = i;
        return;
    }

    TreeNode *solve(const vector<int> &in, const vector<int> &post, unordered_map<int, int> &nodeToIdx, int inorderStart, int inorderEnd,
                    int &postIdx) {
        if (postIdx < 0 || inorderStart > inorderEnd) return nullptr;

        int element = post[postIdx];
        TreeNode *root = new TreeNode(element);
        int position = nodeToIdx[element];
        postIdx--;

        root->right = solve(in, post, nodeToIdx, position + 1, inorderEnd, postIdx);
        root->left = solve(in, post, nodeToIdx, inorderStart, position - 1, postIdx);

        return root;
    }
public:
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        int n = inorder.size();
        int postOrderIdx = n - 1;

        unordered_map<int, int> nodeToIdx;
        createMapping(inorder, nodeToIdx, n);
        TreeNode *ans = solve(inorder, postorder, nodeToIdx, 0, n - 1, postOrderIdx);
        return ans;
    }
};