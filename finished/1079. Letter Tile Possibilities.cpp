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
    array<int, 26> freq{};
    int ans = 0;
    int factorial(int n) {
        int res = 1;
        for (int i = 1; i <= n; i++) res *= i;
        return res;
    }
    void backtrack(size_t pos, int len, int divisor) {
        if (pos == 26) {
            if (!len) return;
            ans += factorial(len) / divisor;
            return;
        }
        if (!freq[pos]) {
            backtrack(pos + 1, len, divisor);
            return;
        }
        for (auto i = 1; i <= freq[pos]; i++) backtrack(pos + 1, len + i, divisor * factorial(i));
        backtrack(pos + 1, len, divisor);
    }
public:
    int numTilePossibilities(string tiles) {
        for (const auto &t : tiles) freq[t - 'A']++;
        backtrack(0uz, 0, 1);
        return ans;
    }
};