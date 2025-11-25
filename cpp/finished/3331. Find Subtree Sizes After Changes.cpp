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

#include <ranges>
class Solution {
    using children_t = unordered_multimap<int, int>;
    using ancestors_t = array<stack<int>, 26>;
    void dfs(int node, vector<int> &parent, children_t &children, ancestors_t &ancestors,
             const string &s) {
        for (auto [begin, end] = children.equal_range(node);
             const auto &[node, child] : std::ranges::subrange(begin, end)) {
            if (!ancestors[s[child] - 'a'].empty()) parent[child] = ancestors[s[child] - 'a'].top();
            ancestors[s[child] - 'a'].push(child);
            dfs(child, parent, children, ancestors, s);
            ancestors[s[child] - 'a'].pop();
        }
    }
    int get_subtree_size(int node, const children_t &children, vector<int> &subtree_size) {
        subtree_size[node] = 1;
        for (auto [begin, end] = children.equal_range(node);
             const auto &[node, child] : std::ranges::subrange(begin, end)) {
            subtree_size[node] += get_subtree_size(child, children, subtree_size);
        }
        return subtree_size[node];
    }
public:
    vector<int> findSubtreeSizes(vector<int> &parent, string s) {
        const auto n = parent.size();

        children_t children; // parent, child
        for (const auto &i : parent | std::views::drop(1)) children.emplace(i, &i - parent.data());

        ancestors_t ancestors; // char, nearest ancestor
        ancestors[s[0] - 'a'].push(0);
        dfs(0, parent, children, ancestors, s);

        vector<int> subtree_size(n);
        children.clear();
        for (const auto &i : parent | std::views::drop(1)) children.emplace(i, &i - parent.data());
        get_subtree_size(0, children, subtree_size);
        return subtree_size;
    }
};