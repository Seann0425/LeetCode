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
    vector<int> avoidFlood(vector<int> &rains) {
        const auto n = rains.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> full;
        set<int> empty;
        for (auto i = 0uz; i < n; i++) {
            if (!rains[i]) {
                empty.insert(i);
                ans[i] = 1;
            } else {
                if (full.find(rains[i]) != full.end()) {
                    auto it = empty.lower_bound(full[rains[i]]);
                    if (it == empty.end()) return {};
                    ans[*it] = rains[i];
                    empty.erase(it);
                }
                full[rains[i]] = i;
            }
        }
        return ans;
    }
};