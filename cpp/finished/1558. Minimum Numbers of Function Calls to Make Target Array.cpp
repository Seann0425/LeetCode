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
    int minOperations(vector<int> &nums) {
        auto ans = 0, levels = 0;
        for (const auto &num : nums) {
            ans += popcount(static_cast<unsigned>(num));
            levels = max(levels, 32 - countl_zero(static_cast<unsigned>(num)));
        }
        return max(ans + levels - 1, 0);
    }
};

// class Solution {
// public:
//     int minOperations(vector<int> &nums) {
//         auto steps = 0;
//         for (auto num : nums) {
//             steps += num % 2;
//             num /= 2;
//         }
//         if (all_of(nums.begin(), nums.end(), [](int num) { return num == 0; })) return steps;
//         return minOperations(nums) + steps + 1;
//     }
// };