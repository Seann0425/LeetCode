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
    int numTilings(size_t n) {
        vector<int> fibo(n);
        const int mod = 1e9 + 7;
        auto accum = 1;
        for (size_t i = 0; i < n; i++) {
            if (i == 0) fibo[i] = 1;
            else if (i == 1) fibo[i] = 2;
            else {
                fibo[i] = (static_cast<long long>(fibo[i - 1]) % mod + fibo[i - 2] % mod +
                           2 * accum % mod) %
                          mod;
                accum = (accum + fibo[i - 2]) % mod;
            }
        }
        return fibo.back();
    }
};