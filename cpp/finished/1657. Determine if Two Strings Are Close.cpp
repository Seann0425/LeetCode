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
    bool closeStrings(string word1, string word2) {
        // i don't even know what i am doing
        unordered_map<int, int> map1, map2;
        array<int, 26> freq{};
        bitset<26> exist1, exist2;
        for (const auto &c : word1) freq[c - 'a']++, exist1[c - 'a'] = 1;
        for (const auto &f : freq)
            if (f) map1[f]++;
        fill(freq.begin(), freq.end(), 0);
        for (const auto &c : word2) freq[c - 'a']++, exist2[c - 'a'] = 1;
        for (const auto &f : freq)
            if (f) map2[f]++;
        return map1 == map2 && exist1 == exist2;
    }
};