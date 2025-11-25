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
    bitset<10> used{};
    size_t n;
    bool backtrack(const string &pattern, size_t i, string &ans) {
        if (i == n + 1) return true;
        auto initial = i ? (pattern[i - 1] == 'I' ? ans.back() - '0' + 1 : 1) : 1;
        auto final = i ? (pattern[i - 1] == 'I' ? 10 : ans.back() - '0') : 10;
        for (auto d = initial; d < final; d++) {
            if (used[d]) continue;
            used[d] = true;
            ans.push_back('0' + d);
            if (backtrack(pattern, i + 1, ans)) return true;
            ans.pop_back();
            used[d] = false;
        }
        return false;
    }
public:
    string smallestNumber(string pattern) {
        n = pattern.size();
        string ans{};
        ans.reserve(n + 1);
        backtrack(pattern, 0uz, ans);
        return ans;
    }
};