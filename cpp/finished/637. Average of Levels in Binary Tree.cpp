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
    struct LooksCool {
        double sum;
        int count;
        LooksCool(int _sum, int _count) {
            sum = _sum;
            count = _count;
        }
    };
    vector<LooksCool> level;
public:
    void combine(TreeNode *root, int lv) {
        if (!root) return;
        if (lv == level.size()) {
            LooksCool cool(root->val, 1);
            level.push_back(cool);
        } else {
            level[lv].sum += root->val;
            level[lv].count++;
        }
        combine(root->left, lv + 1);
        combine(root->right, lv + 1);
        return;
    }

    vector<double> averageOfLevels(TreeNode *root) {
        ios_base::sync_with_stdio(0);
        combine(root, 0);
        int n = level.size();
        vector<double> avg;
        for (int i = 0; i < n; i++) {
            avg.push_back((level[i].sum) / (level[i].count));
        }
        return avg;
    }
};