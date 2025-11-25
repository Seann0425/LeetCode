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
    int minimumCost(size_t m, size_t n, vector<int> &h, vector<int> &v) {
        auto hori_count = 1, vert_count = 1, ans = 0;
        priority_queue<int> hori_edge(h.begin(), h.end());
        priority_queue<int> vert_edge(v.begin(), v.end());
        while (!hori_edge.empty() and !vert_edge.empty()) {
            if (hori_edge.top() > vert_edge.top()) {
                ans += hori_edge.top() * vert_count;
                hori_edge.pop();
                hori_count++;
            } else {
                ans += vert_edge.top() * hori_count;
                vert_edge.pop();
                vert_count++;
            }
        }
        while (!hori_edge.empty()) {
            ans += hori_edge.top() * vert_count;
            hori_edge.pop();
        }
        while (!vert_edge.empty()) {
            ans += vert_edge.top() * hori_count;
            vert_edge.pop();
        }
        return ans;
    }
};