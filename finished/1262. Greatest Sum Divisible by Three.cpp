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
    int maxSumDivThree(vector<int> &nums) {
        auto zero = 0, one = 0, two = 0;
        for (const auto &i : nums) {
            if (i % 3 == 0) {
                zero += i;
                if (one) one += i;
                if (two) two += i;
            } else if (i % 3 == 1) {
                auto tmp = one;
                one = max(one, zero + i);
                if (two) zero = max(zero, two + i);
                if (tmp) two = max(two, tmp + i);
            } else {
                auto tmp = two;
                two = max(two, zero + i);
                if (one) zero = max(zero, one + i);
                if (tmp) one = max(one, tmp + i);
            }
        }
        return zero;
    }
};