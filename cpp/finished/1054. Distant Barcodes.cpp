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
    vector<int> rearrangeBarcodes(vector<int> &barcodes) {
        array<int, 10005> cnt{};
        for (const auto &i : barcodes) cnt[i]++;
        const auto n = barcodes.size();
        priority_queue<pair<int, int>> pq;
        for (auto i = 0; i < 10005; i++)
            if (cnt[i]) pq.emplace(cnt[i], i);
        auto i = 0uz;
        // since the answer is guanranteed to exist, we can optimized this part
        while (!pq.empty()) {
            auto [cnt1, val1] = pq.top();
            pq.pop();
            if (pq.empty()) {
                barcodes[i] = val1;
                break;
            }
            auto [cnt2, val2] = pq.top();
            pq.pop();
            barcodes[i++] = val1;
            barcodes[i++] = val2;
            if (--cnt1) pq.emplace(cnt1, val1);
            if (--cnt2) pq.emplace(cnt2, val2);
        }
        return barcodes;
    }
};