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
        bool sign = false, number = false;
        uint32_t ans = 0;
        for (const auto &ch : s) {
            if (number && !isdigit(ch) || ans == -1) break;
            if (!number) {
                switch (ch) {
                case ' ':
                    continue;
                case '-':
                    sign = true;
                    number = true;
                    break;
                default:
                    if (isdigit(ch)) {
                        ans = (ch - '0');
                        number = true;
                    } else ans = -1;
                    break;
                }
            } else ans = ans * 10 + (ch - '0');
            if (ans > INT_MAX && !sign) return INT_MAX;
            if (ans > static_cast<unsigned>(INT_MAX) + 1 && sign) return INT_MIN;
        }
        return sign ? -1 * max(0U, ans) : max(0U, ans);
    }
};