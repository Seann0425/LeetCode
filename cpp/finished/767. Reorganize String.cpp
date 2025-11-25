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
public:
    string reorganizeString(string s) {
        freq_t freq{};
        for (const auto &c : s) freq[c - 'a']++;
        priority_queue<pair<int, char>> pq;
        for (auto i = 0uz; i < 26; i++)
            if (freq[i]) pq.emplace(freq[i], i + 'a');
        const auto n = s.size();
        string ans;
        ans.reserve(n);
        while (!pq.empty()) {
            auto [f1, c1] = pq.top();
            pq.pop();
            if (pq.empty()) {
                if (f1 > 1) return "";
                ans.push_back(c1);
                break;
            }
            auto [f2, c2] = pq.top();
            pq.pop();
            ans.push_back(c1);
            ans.push_back(c2);
            if (--f1) pq.emplace(f1, c1);
            if (--f2) pq.emplace(f2, c2);
        }
        return ans;
    }
};