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
    using subseq_t = pair<int, int>; // tail, n-th
    struct cmp {
        bool operator()(const subseq_t &a, const subseq_t &b) const {
            if (a.first == b.first) return a.second > b.second;
            return a.first > b.first;
        }
    };
public:
    bool isPossible(vector<int> &nums) {
        priority_queue<subseq_t, vector<subseq_t>, cmp> subsequences; // tail, n-th
        for (const auto &i : nums) {
            while (!subsequences.empty() and subsequences.top().first + 1 < i) {
                if (subsequences.top().second < 3) return false;
                subsequences.pop();
            }
            if (subsequences.empty() or subsequences.top().first == i) subsequences.emplace(i, 1);
            else {
                auto [tail, n] = subsequences.top();
                subsequences.pop();
                subsequences.emplace(i, n + 1);
            }
        }
        while (!subsequences.empty()) {
            if (subsequences.top().second < 3) return false;
            subsequences.pop();
        }
        return true;
    }
};