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

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        array<int, 26> freq{};
        auto diff = 0;
        const auto n = s1.size();
        for (auto i = 0uz; i < n; i++)
            if (s1[i] != s2[i]) {
                diff++;
                freq[s1[i] - 'a']++;
                freq[s2[i] - 'a']--;
                if (diff > 2) return false;
            }
        return !diff or
               (diff == 2 and all_of(freq.begin(), freq.end(), [](const auto &f) { return !f; }));
    }
};