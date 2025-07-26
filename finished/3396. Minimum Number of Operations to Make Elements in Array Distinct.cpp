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
    bool not_one(const array<int, 105> &count) {
        for (const auto &i : count) {
            if (i > 1) return true;
        }
        return false;
    }
public:
    int minimumOperations(vector<int> &nums) {
        array<int, 105> count{};
        for (const auto &num : nums) count[num]++;
        auto ans = 0;
        const auto n = nums.size();
        for (auto i = 0; i < n; i += 3) {
            if (not_one(count)) {
                count[nums[i]]--;
                if (i + 1 < n) count[nums[i + 1]]--;
                if (i + 2 < n) count[nums[i + 2]]--;
                ans++;
            } else break;
        }
        return ans;
    }
};