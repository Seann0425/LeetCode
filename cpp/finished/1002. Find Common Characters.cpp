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
    vector<string> commonChars(vector<string> &words) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> common(26, INT_MAX);
        // find all common characters including duplicates
        for (string &s : words) {
            vector<int> alpha(26, 0);
            for (int i = 0; i < s.size(); i++)
                alpha[s[i] - 'a']++;
            for (int i = 0; i < 26; i++)
                common[i] = min(common[i], alpha[i]);
        }
        // store
        vector<string> CChars;
        for (int i = 0; i < 26; i++) {
            while (common[i]--) {
                char c = 'a' + i;
                string s(1, c);
                CChars.push_back(s);
            }
        }
        return CChars;
    }
};