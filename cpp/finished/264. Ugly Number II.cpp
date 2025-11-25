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
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

const size_t max_n = 1690;

constexpr auto ans = []() consteval {
    array<int, max_n> tmp{1};
    size_t pos_2 = 0, pos_3 = 0, pos_5 = 0;
    int prod_2 = 2, prod_3 = 3, prod_5 = 5;
    for (size_t i = 1; i < max_n; i++) {
        tmp[i] = min({prod_2, prod_3, prod_5});
        if (tmp[i] == prod_2) prod_2 = tmp[++pos_2] * 2;
        if (tmp[i] == prod_3) prod_3 = tmp[++pos_3] * 3;
        if (tmp[i] == prod_5) prod_5 = tmp[++pos_5] * 5;
    }
    return tmp;
}();

class Solution {
public:
    int nthUglyNumber(int n) {
        return ans[static_cast<size_t>(n - 1)];
    }
};