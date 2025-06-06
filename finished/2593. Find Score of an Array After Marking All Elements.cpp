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

constexpr size_t max_n = 1e5 + 5;
class Solution {
    using piz = pair<int, size_t>;
public:
    long long findScore(vector<int> &nums) {
        priority_queue<piz, vector<piz>, greater<piz>> pq;
        bitset<max_n> marked{};
        const auto n = nums.size();
        for (size_t i = 0; i < n; i++) pq.emplace(nums[i], i);
        auto ans = 0ll;
        while (!pq.empty()) {
            const auto [val, index] = pq.top();
            pq.pop();
            if (marked[index]) continue;
            marked[index] = marked[index + 1] = true;
            if (index) marked[index - 1] = true;
            ans += val;
        }
        return ans;
    }
};