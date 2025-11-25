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
    string minimizeStringValue(string s) {
        array<int, 26> alphabet{};
        for (const auto &ch : s)
            if (ch != '?') alphabet[ch - 'a']++;
        string insert = "";
        for (const auto &ch : s) {
            if (ch == '?') {
                int min_freq = 0;
                for (int i = 0; i < 26; i++) {
                    if (alphabet[i] < alphabet[min_freq]) min_freq = i;
                }
                alphabet[min_freq]++;
                insert.push_back(('a' + min_freq));
            }
        }
        sort(insert.begin(), insert.end());
        for (int i = 0, j = 0; i < static_cast<int>(s.size()); i++) {
            if (s[i] == '?') s[i] = insert[j++];
        }
        return s;
    }
};