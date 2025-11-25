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
    bool checkInclusion(string s1, string s2) {
        const auto n1 = s1.size(), n2 = s2.size();
        if (n1 > n2) return false;
        array<int, 26> window{};
        for (const auto &c : s1) window[c - 'a']++;
        for (size_t i = 0; i < n1; i++) {
            window[s2[i] - 'a']--;
            if (window[s2[i] - 'a'] == 0) {
                for (size_t j = 0; j < 26; j++) {
                    if (window[j]) break;
                    if (j == 25) return true;
                }
            }
        }
        for (size_t l = 0, r = n1; r < n2; l++, r++) {
            window[s2[l] - 'a']++;
            window[s2[r] - 'a']--;
            if (!window[s2[r] - 'a'] && !window[s2[l] - 'a']) {
                for (size_t i = 0; i < 26; i++) {
                    if (window[i]) break;
                    if (i == 25) return true;
                }
            }
        }
        return false;
    }
};