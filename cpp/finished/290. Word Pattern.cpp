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
    bool wordPattern(string pattern, string s) {
        int n = pattern.size();
        map<char, string> CtoS;
        map<string, char> StoC;
        stringstream str;
        string word;
        str << s;
        for (int i = 0; i < n; i++) {
            str >> word;
            if (str.fail()) return false;
            if (!CtoS.count(pattern[i]) && !StoC.count(word)) {
                CtoS[pattern[i]] = word;
                StoC[word] = pattern[i];
                cout << 1;
            } else if (CtoS[pattern[i]] != word || StoC[word] != pattern[i]) return false;
        }
        str >> word;
        if (!str.fail()) return false;
        return true;
    }
};