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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class FindElements {
    TreeNode *root;
    bitset<2100000> hash{};
    void dfs(TreeNode *node) {
        hash.set(node->val);
        if (node->left) {
            node->left->val = node->val * 2 + 1;
            dfs(node->left);
        }
        if (node->right) {
            node->right->val = node->val * 2 + 2;
            dfs(node->right);
        }
    }
    bool dfs_find(TreeNode *node, int val) {
        if (!node) return false;
        if (val > node->val) return dfs_find(node->right, val);
        if (val < node->val) return dfs_find(node->left, val);
        return true;
    }
public:
    FindElements(TreeNode *root) {
        root->val = 0;
        dfs(root);
        this->root = root;
    }

    bool find(int target) { return hash.test(target); }
};