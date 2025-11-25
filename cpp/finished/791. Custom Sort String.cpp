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
    string customSortString(string order, string s) {
        string ans;
        vector<int> freq(26, 0);
        for (const auto &ch : s)
            freq[ch - 'a']++;

        for (const auto &ch : order) {
            while (freq[ch - 'a']) {
                ans += ch;
                freq[ch - 'a']--;
            }
        }
        for (char i = 'a'; i - 'a' < 26; i++) {
            while (freq[i - 'a']) {
                ans.push_back(i);
                freq[i - 'a']--;
            }
        }
        return ans;
    }
};