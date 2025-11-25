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
    void buildTable(unordered_map<char, int> &table, string &order) {
        for (int i = 0; i < order.size(); i++) {
            table[order[i]] = i;
        }
        return;
    }

    bool lexi(string &a, string &b, unordered_map<char, int> &table) {
        // return whether b>a
        int n = max(a.size(), b.size());
        for (int i = 0; i < n; i++) {
            int prev = (i < a.size()) ? table[a[i]] : -1;
            int cur = (i < b.size()) ? table[b[i]] : -1;
            if (cur == prev) continue;
            else if (cur > prev) return true;
            else return false;
        }
        return true;
    }
public:
    bool isAlienSorted(vector<string> &words, string order) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        unordered_map<char, int> table;
        buildTable(table, order);
        for (int i = 1; i < words.size(); i++)
            if (!lexi(words[i - 1], words[i], table)) return false;
        return true;
    }
};