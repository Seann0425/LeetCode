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
    int min_swap(vector<int> &arr) {
        const auto n = arr.size();
        map<int, size_t> idx;
        for (auto i = 0uz; i < n; i++) idx[arr[i]] = i;
        sort(arr.begin(), arr.end());
        vector<bool> visited(n, false);
        auto ans = 0;
        for (auto i = 0uz; i < n; i++) {
            if (visited[i] or idx[arr[i]] == i) continue;
            auto cycle_size = 0;
            auto j = i;
            while (!visited[j]) {
                visited[j] = true;
                j = idx[arr[j]];
                cycle_size++;
            }
            ans += cycle_size - 1;
        }
        return ans;
    }
public:
    int minimumOperations(TreeNode *root) {
        queue<TreeNode *> q;
        q.push(root);
        auto ans = 0;
        while (!q.empty()) {
            auto n = q.size();
            vector<int> next; // root must be sorted
            for (auto i = 0uz; i < n; i++) {
                auto node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                    next.push_back(node->left->val);
                }
                if (node->right) {
                    q.push(node->right);
                    next.push_back(node->right->val);
                }
            }
            ans += min_swap(next);
        }
        return ans;
    }
};