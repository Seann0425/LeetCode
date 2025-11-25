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
    string longestDiverseString(int a, int b, int c) {
        string ans{};
        priority_queue<pair<int, char>> freq;
        if (a) freq.emplace(a, 'a');
        if (b) freq.emplace(b, 'b');
        if (c) freq.emplace(c, 'c');
        while (!freq.empty()) {
            auto [left, character] = freq.top();
            freq.pop();
            if (ans.size() >= 2 && ans.back() == character && ans[ans.size() - 2] == character) {
                if (freq.empty()) break;
                auto [left2, character2] = freq.top();
                freq.pop();
                ans.push_back(character2);
                if (--left2) freq.emplace(left2, character2);
                freq.emplace(left, character);
            } else {
                ans.push_back(character);
                if (--left) freq.emplace(left, character);
            }
        }
        return ans;
    }
};