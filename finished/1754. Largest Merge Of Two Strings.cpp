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
    string largestMerge(string word1, string word2) {
        string ans{};
        const auto n = word1.size(), m = word2.size();
        auto i = 0uz, j = 0uz;
        while (i < n and j < m) {
            if (word1[i] > word2[j]) ans += word1[i++];
            else if (word1[i] < word2[j]) ans += word2[j++];
            else {
                auto x = i, y = j;
                while (x < n and y < m and word1[x] == word2[y]) x++, y++;
                if (x == n or (y < m and word1[x] < word2[y])) ans += word2[j++];
                else ans += word1[i++];
            }
        }
        if (i < n) return ans + word1.substr(i);
        return ans + word2.substr(j);
    }
};