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
    string shortestPalindrome(string s) {
        if (s.empty()) return {};
        string str(s);
        reverse(s.begin(), s.end());
        s.pop_back();
        s += str;
        const auto n = s.size();
        vector<size_t> lps(n);

        // build lps and find candidate
        size_t i = 1, prev = 0;
        size_t candidate = 0;
        while (i < n) {
            if (s[i] == s[prev]) {
                lps[i] = prev++ + 1;
                if ((lps[i] == n - i - 1 or lps[i] == n - i - 2) and i - lps[i] + 1 <= n / 2)
                    candidate = i;
                i++;
            } else if (!prev) {
                lps[i] = 0;
                i++;
            } else prev = lps[prev - 1];
        }
        auto ans = candidate - lps[candidate] + 1;
        return s.substr(candidate ? ans : 0);
    }
};