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
    bool isNice(vector<int> &lower, vector<int> &upper) {
        for (int i = 0; i < 26; i++)
            if ((lower[i] == 0 && upper[i] != 0) || (lower[i] != 0 && upper[i] == 0)) return false;
        return true;
    }
public:
    string longestNiceSubstring(string s) {
        vector<int> lowerCase(26, 0), upperCase(26, 0);
        for (char c : s) {
            if (islower(c)) lowerCase[c - 'a']++;
            else upperCase[c - 'A']++;
        }
        int n = s.size();
        int tmpN = n;
        while (tmpN > 1) {
            vector<int> tmpLower(lowerCase.begin(), lowerCase.end());
            vector<int> tmpUpper(upperCase.begin(), upperCase.end());
            if (isNice(tmpLower, tmpUpper)) return s.substr(0, tmpN);
            for (int i = 1; i < n - tmpN + 1; i++) {
                if (islower(s[i - 1])) tmpLower[s[i - 1] - 'a']--;
                else tmpUpper[s[i - 1] - 'A']--;
                if (islower(s[i - 1 + tmpN])) tmpLower[s[i - 1 + tmpN] - 'a']++;
                else tmpUpper[s[i - 1 + tmpN] - 'A']++;
                if (isNice(tmpLower, tmpUpper)) return s.substr(i, tmpN);
            }
            if (islower(s[tmpN - 1])) lowerCase[s[tmpN - 1] - 'a']--;
            else upperCase[s[tmpN - 1] - 'A']--;
            tmpN--;
        }
        return "";
    }
};