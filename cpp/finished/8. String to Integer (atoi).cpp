#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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
// static const auto __ = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    int myAtoi(string s) {
        const auto N = s.size();
        size_t i = 0;

        while (isspace(s[i]))
            i++;

        bool sign = false;
        if (s[i] == '+' || s[i] == '-') sign = (s[i++] == '-');

        int ans = 0;
        for (; i < N && isdigit(s[i]); i++) {
            auto digit = s[i] - '0';
            if (ans > INT_MAX / 10 || (ans *= 10) > INT_MAX - digit) return sign ? INT_MIN : INT_MAX;
            ans += digit;
        }
        return sign ? -ans : ans;
    }
};