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
    bool isCompletingWord(unordered_map<char, int> table, string target, int size) {
        for (auto c : target) {
            if (!table.count(c)) continue;
            table[c]--;
            if (table[c] == 0) size--;
        }
        if (size) return false;
        return true;
    }

    string shortestCompletingWord(string licensePlate, vector<string> &words) {
        unordered_map<char, int> licenseTable;
        int mn = INT_MAX;
        string ans;
        for (auto c : licensePlate) {
            if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) licenseTable[tolower(c)]++;
        }
        int size = licenseTable.size();
        for (auto s : words) {
            if (isCompletingWord(licenseTable, s, size) && s.size() < mn) {
                ans = s;
                mn = s.size();
            }
        }
        return ans;
    }
};