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
    bool is_subset(const freq_t &freq1, const freq_t &freq2) {
        for (auto i = 0uz; i < 26; i++)
            if (freq1[i] < freq2[i]) return false;
        return true;
    }
    void to_freq(const string &word, freq_t &freq) {
        for (const auto &ch : word) freq[ch - 'a']++;
    }
public:
    vector<string> wordSubsets(vector<string> &words1, vector<string> &words2) {
        vector<string> ans;
        const auto n = words1.size(), m = words2.size();
        freq_t max_freq{};
        for (auto i = 0uz; i < m; i++) {
            freq_t freq{};
            to_freq(words2[i], freq);
            for (auto j = 0uz; j < 26; j++) max_freq[j] = max(max_freq[j], freq[j]);
        }
        for (auto i = 0uz; i < n; i++) {
            freq_t freq1{};
            to_freq(words1[i], freq1);
            if (is_subset(freq1, max_freq)) ans.push_back(words1[i]);
        }
        return ans;
    }
};