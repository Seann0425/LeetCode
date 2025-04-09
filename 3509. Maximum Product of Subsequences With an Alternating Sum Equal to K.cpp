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

#pragma GCC optimize("O3", "unroll-loops")
#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    int maxProduct(vector<int> &nums, int k, int limit) {}
};

// python solution
// class Solution:
//     def maxProduct(self, nums: List[int], k: int, limit: int) -> int:
//         n = len(nums)
//         even_lengths, odd_lengths = defaultdict(int), defaultdict(int)
//         even_lengths[(0, 1)] = 1
//         ans = -1
//         for i in range(n):
//             tmp_odd = defaultdict(int)
//             for ((sum, product), count) in even_lengths.items():
//                 tuple = (sum + nums[i], limit + 1 if product * nums[i] > limit else product *
//                 nums[i]) tmp_odd[tuple] += count if tuple[0] == k and tuple[1] <= limit:
//                     ans = max(ans, tuple[1])
//             for ((sum, product), count) in odd_lengths.items():
//                 tuple = (sum - nums[i], limit + 1 if product * nums[i] > limit else product *
//                 nums[i]) even_lengths[tuple] += count if tuple[0] == k and tuple[1] <= limit:
//                     ans = max(ans, tuple[1])
//             for (key, count) in tmp_odd.items():
//                 odd_lengths[key] += count
//         return ans