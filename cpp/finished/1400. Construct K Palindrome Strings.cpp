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
    using freq_t = array<int, 26>;
    int odd_check(const freq_t &freq, int k) {
        auto odd_count = 0;
        for (const auto &count : freq) {
            if (count % 2) odd_count++;
            if (odd_count > k) return odd_count;
        }
        return odd_count;
    }
    bool empty_check(const freq_t &freq, int k, int odd_count) {
        if (odd_count > k) return false;
        auto pair_count = 0;
        for (const auto &count : freq) {
            pair_count += count / 2;
            if (pair_count + odd_count >= k) return true;
        }
        return k - odd_count <= pair_count * 2;
    }
public:
    bool canConstruct(string s, int k) {
        freq_t freq{};
        for (const auto &c : s) freq[c - 'a']++;
        return empty_check(freq, k, odd_check(freq, k));
    }
};