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
    size_t n;
    int k;
    void backtrack(string &ans) {
        if (ans.size() == n) return --k, void();
        for (auto c : views::iota('a', 'd')) {
            if (!ans.empty() and ans.back() == c) continue;
            ans.push_back(c);
            backtrack(ans);
            if (!k) return;
            ans.pop_back();
        }
    }
public:
    string getHappyString(int n, int k) {
        this->n = n;
        this->k = k;
        string ans{};
        ans.reserve(n);
        backtrack(ans);
        return ans;
    }
};