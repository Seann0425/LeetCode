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
    int longestPalindrome(string s) {
        vector<int> lower(26, 0), upper(26, 0);
        int sum = 0;
        int n = s.size();
        for (int i = 0; i < n; i++) {
            if (s[i] >= 'a' && s[i] <= 'z') lower[s[i] - 'a']++;
            else upper[s[i] - 'A']++;
        }
        for (int i = 0; i < 26; i++)
            sum = sum + (lower[i] / 2) + (upper[i] / 2);
        sum *= 2;
        if (sum < n) sum++;
        return sum;
    }
};