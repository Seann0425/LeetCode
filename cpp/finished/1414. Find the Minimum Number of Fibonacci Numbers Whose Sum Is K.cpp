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

static constexpr array<int, 47> fib = []() consteval {
    array<int, 47> fib{};
    fib[1] = fib[2] = 1;
    for (auto i = 3; i < 47; i++) fib[i] = fib[i - 1] + fib[i - 2];
    return fib;
}();

class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        auto ans = 0;
        for (auto i = 46; i > 0 and k > 0; i--)
            if (k >= fib[i]) {
                ans += k / fib[i];
                k %= fib[i];
            }
        return ans;
    }
};