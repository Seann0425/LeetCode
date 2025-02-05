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
    auto get_sum(size_t n, size_t index, long long val) -> long long {
        auto sum = 0ll;
        if (val <= index) {
            sum += (val + 1) * val / 2;
            sum += index - val + 1;
        } else {
            sum += (2 * val - index) * (index + 1) / 2;
        }
        if (val < n - index) {
            sum += (val + 1) * val / 2;
            sum += n - index - val;
        } else {
            sum += (2 * val - n + index + 1) * (n - index) / 2;
        }
        return sum - val;
    }
public:
    int maxValue(size_t n, size_t index, int max_sum) {
        auto left = 1, right = max_sum;
        while (left < right) {
            auto mid = left + (right - left) / 2 + 1;
            if (get_sum(n, index, mid) <= max_sum) left = mid;
            else right = mid - 1;
        }
        return left;
    }
};