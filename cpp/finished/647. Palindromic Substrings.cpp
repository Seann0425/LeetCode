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
    int countSubstrings(string s) {
        const int n = s.size();
        vector<vector<bool>> isSubstring(n, vector<bool>(n));
        int cnt = n;
        // length = 1
        for (int i = 0; i < n; i++)
            isSubstring[i][i] = true;
        // length = 2
        for (int i = 1; i < n; i++)
            if (s[i] == s[i - 1]) {
                isSubstring[i - 1][i] = true;
                cnt++;
            }

        for (int length = 3; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                // starting index
                if (isSubstring[i + 1][i + length - 2] == true && s[i] == s[i + length - 1]) {
                    cnt++;
                    isSubstring[i][i + length - 1] = true;
                }
            }
        }

        return cnt;
    }
};