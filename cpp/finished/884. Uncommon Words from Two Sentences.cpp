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
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> common;
        vector<string> uncommon;
        stringstream ss;
        string word;

        ss << s1;
        while (ss >> word) common[word]++;
        ss.clear();
        ss << s2;
        while (ss >> word) common[word]++;
        for (const auto [w, c] : common)
            if (c == 1) uncommon.push_back(std::move(w));
        return uncommon;
    }
};

// class Solution {
// public:
//     vector<string> uncommonFromSentences(string s1, string s2) {
//         vector<string> uncommon;
//         unordered_map<string, int> occur;
//         stringstream ss;
//         ss << s1;
//         string tmp;
//         while (ss >> tmp)
//             occur[tmp]++;
//         ss.clear();
//         ss << s2;
//         while (ss >> tmp)
//             occur[tmp]++;
//         for (auto itr = occur.begin(); itr != occur.end(); itr++) {
//             if (itr->second == 1) uncommon.push_back(itr->first);
//         }
//         return uncommon;
//     }
// };