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
    bool checkIfCanBreak(string s1, string s2) {
        const auto n = s1.size();
        array<int, 26> freq1{}, freq2{};
        for (const auto &i : s1) freq1[i - 'a']++;
        for (const auto &i : s2) freq2[i - 'a']++;
        for (auto i = 0uz; i < 26uz; i++) {
            if (freq1[i] == freq2[i]) continue;
            if (freq1[i] > freq2[i]) swap(freq1, freq2);
            break;
        }
        auto count = 0;
        for (auto i = 0uz; i < 26uz; i++)
            if ((count += (freq2[i] - freq1[i])) < 0) return false;
        return true;
    }
};