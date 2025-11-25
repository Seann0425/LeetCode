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
public:
    bool flipEquiv(TreeNode *root1, TreeNode *root2) {
        if ((!root1 && root2) or (root1 && !root2)) return false;
        if (!root1 && !root2) return true;
        if (root1->val != root2->val) return false;

        auto left1 = root1->left, right1 = root1->right;
        auto left2 = root2->left, right2 = root2->right;
        if (!left1 && !right1 && !left2 && !right2) return true;
        if ((!left1 && right1) && ((!left2 && right2) or (left2 && !right2))) {
            if (left2 && !right2) swap(left2, right2);
            return flipEquiv(right1, right2);
        } else if ((left1 && !right1) && ((left2 && !right2) or (!left2 && right2))) {
            if (!left2 && right2) swap(left2, right2);
            return flipEquiv(left1, left2);
        } else if (left1 && right1 && left2 && right2) {
            if (left1->val == left2->val or left1->val == right2->val) {
                if (left1->val == right2->val) swap(left2, right2);
                return flipEquiv(left1, left2) && flipEquiv(right1, right2);
            }
        }
        return false;
    }
};