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

// could be optimized by using two heaps
class Solution {
    using Cost = pair<int, size_t>;
    struct cmp {
        bool operator()(const Cost &a, const Cost &b) {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };
public:
    long long totalCost(vector<int> &costs, int k, int candidates) {
        const auto n = costs.size();
        auto ans = 0ll;
        priority_queue<Cost, vector<Cost>, cmp> hiring;
        auto l = 0uz, r = n - 1;
        for (int i = 0; i < candidates && l <= r; i++) {
            hiring.emplace(costs[l], l);
            l++;
            if (l <= r) {
                hiring.emplace(costs[r], r);
                r--;
            }
        }
        while (k--) {
            const auto [cost, idx] = hiring.top();
            hiring.pop();
            ans += cost;
            if (l <= r) {
                if (idx < l) {
                    hiring.emplace(costs[l], l);
                    l++;
                } else {
                    hiring.emplace(costs[r], r);
                    r--;
                }
            }
        }
        return ans;
    }
};