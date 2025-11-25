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
    size_t n;
    bool exist_thrice(const string &s, size_t window) {
        unordered_map<string_view, int> cnt;
        for (auto l = 0uz, r = 0uz; l < n; l++) { // [l, r)
            while (r < n && r - l < window) {
                if (s[r] != s[l]) break;
                r++;
            }
            if (r - l == window && ++cnt[string_view(s.data() + l, window)] == 3) return true;
            else if (r - l < window) l = r - 1;
        }
        return false;
    }
public:
    int maximumLength(string s) {
        n = s.size();
        auto l = 0uz, r = n - 1;
        while (r < n && l < r) {
            auto m = l + (r - l) / 2 + 1;
            if (exist_thrice(s, m)) l = m;
            else r = m - 1;
        }
        return r ? r : -1;
    }
};