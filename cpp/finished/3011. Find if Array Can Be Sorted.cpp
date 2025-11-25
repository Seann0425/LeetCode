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
    bool canSortArray(vector<int> &nums) {
        const auto n = nums.size();
        array<int, 33> bit_count;
        for (const auto &i : nums) {
            size_t bit = popcount(static_cast<unsigned>(i));
            for (size_t j = 0; j < 33; j++) {
                if (j == bit) continue;
                if (bit_count[j] > i) return false;
            }
            bit_count[bit] = max(bit_count[bit], i);
        }
        return true;
    }
};

// class Solution {
// public:
//     bool canSortArray(vector<int> &nums) {
//         const auto n = nums.size();
//         auto bit_count = unordered_map<int, int>();
//         stable_sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
//             if (!bit_count[a]) bit_count[a] = popcount(static_cast<unsigned>(a));
//             if (!bit_count[b]) bit_count[b] = popcount(static_cast<unsigned>(b));
//             return bit_count[a] == bit_count[b] ? a < b : false;
//         });
//         for (const auto &i : nums) cout << i << " ";
//         for (size_t i = 1; i < n; i++)
//             if (nums[i] < nums[i - 1]) return false;
//         return true;
//     }
// };