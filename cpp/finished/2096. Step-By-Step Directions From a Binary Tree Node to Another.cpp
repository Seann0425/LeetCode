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
    int start, dest;
    string start_path, dest_path;
    void dfs(string &path, TreeNode *node) {
        if (!start_path.empty() && !dest_path.empty()) return;

        // get the path from root to target
        if (node->val == start) start_path = path;
        if (node->val == dest) dest_path = path;

        if (node->left) {
            path.push_back('L');
            dfs(path, node->left);
            path.pop_back();
        }
        if (node->right) {
            path.push_back('R');
            dfs(path, node->right);
            path.pop_back();
        }
    }
public:
    string getDirections(TreeNode *root, int startValue, int destValue) {
        start = startValue;
        dest = destValue;
        string path = "!";

        dfs(path, root);
        const auto n = min(start_path.size(), dest_path.size());
        size_t i;
        for (i = 1; i < n; i++)
            if (start_path[i] != dest_path[i]) break;

        return string(start_path.size() - i, 'U') + dest_path.substr(i, dest_path.size() - i);
    }
};