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
    long long minimumCost(int m, int n, vector<int> &hori_edge, vector<int> &vert_edge) {
        auto hori_count = 1ll, vert_count = 1ll, ans = 0ll;
        sort(hori_edge.begin(), hori_edge.end());
        sort(vert_edge.begin(), vert_edge.end());
        while (!hori_edge.empty() and !vert_edge.empty()) {
            if (hori_edge.back() > vert_edge.back()) {
                ans += hori_edge.back() * vert_count;
                hori_edge.pop_back();
                hori_count++;
            } else {
                ans += vert_edge.back() * hori_count;
                vert_edge.pop_back();
                vert_count++;
            }
        }
        while (!hori_edge.empty()) {
            ans += hori_edge.back() * vert_count;
            hori_edge.pop_back();
        }
        while (!vert_edge.empty()) {
            ans += vert_edge.back() * hori_count;
            vert_edge.pop_back();
        }
        return ans;
    }
};