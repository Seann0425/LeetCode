#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {
    }
    ListNode(int x) : val(x), next(nullptr) {
    }
    ListNode(int x, ListNode *next) : val(x), next(next) {
    }
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {
    }
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {
    }
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {
    }
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
    bool canBeEqual(string s1, string s2) {
        unordered_map<char, int> even, odd;
        const int n = s1.size();
        for (int i = 0; i < n; i++) {
            if (i % 2 == 0) {
                even[s1[i]]++;
                even[s2[i]]--;
            } else {
                odd[s1[i]]++;
                odd[s2[i]]--;
            }
        }
        for (const auto &[ch, cnt] : even)
            if (cnt != 0) return false;
        for (const auto &[ch, cnt] : odd)
            if (cnt != 0) return false;
        return true;
    }
};