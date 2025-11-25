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

/*the solution should start from below*/

constexpr size_t max_n = 46;
constexpr array<int, max_n> fib_seq = []() consteval {
    array<int, max_n> fib_seq{1, 1};
    for (size_t i = 2; i < max_n; i++) fib_seq[i] = fib_seq[i - 1] + fib_seq[i - 2];
    return fib_seq;
}();

class Solution {
public:
    int climbStairs(size_t n) { return fib_seq[n]; }
};