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
    string smallestSubsequence(string s) {
        const auto n = s.size();
        string ans;
        bitset<26> in_stack;
        array<int, 26> last_seen{};
        for (auto i = 0uz; i < n; i++) last_seen[s[i] - 'a'] = i;
        for (auto i = 0uz; i < n; i++) {
            if (in_stack.test(s[i] - 'a')) continue;
            while (!ans.empty() and ans.back() > s[i] and last_seen[ans.back() - 'a'] > i) {
                in_stack.reset(ans.back() - 'a');
                ans.pop_back();
            }
            ans.push_back(s[i]);
            in_stack.set(s[i] - 'a');
        }
        return ans;
    }
};