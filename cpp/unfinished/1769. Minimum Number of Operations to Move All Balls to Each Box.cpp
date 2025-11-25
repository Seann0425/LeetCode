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
    vector<int> minOperations(string boxes) {
        const auto n = boxes.size();
        vector<int> from_left(n), from_right(n), ans(n);
        auto left_balls = 0, right_balls = 0;
        for (auto i = 1uz; i < n; i++) {
            left_balls += boxes[i - 1] - '0';
            from_left[i] = from_left[i - 1] + left_balls;
        }
        for (auto i = n - 2; i < n; i--) {
            right_balls += boxes[i + 1] - '0';
            from_right[i] = from_right[i + 1] + right_balls;
        }
        for (auto i = 0uz; i < n; i++) { ans[i] = from_left[i] + from_right[i]; }
        return ans;
    }
};