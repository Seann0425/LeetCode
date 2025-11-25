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
    string licenseKeyFormatting(string s, int k) {
        string licenseKey;
        licenseKey.reserve(s.size());

        int start = 0;
        int end = s.size() - 1;

        int subStringCount = k;
        for (; end >= start; --end) {
            char c = toupper(s.at(end));
            if (c == '-') continue;
            licenseKey += c;
            --subStringCount;
            if (subStringCount == 0) {
                licenseKey += '-';
                subStringCount = k;
            }
        }
        if (!licenseKey.empty() && licenseKey.back() == '-') licenseKey.pop_back();

        reverse(licenseKey.begin(), licenseKey.end());
        return licenseKey;
    }
};