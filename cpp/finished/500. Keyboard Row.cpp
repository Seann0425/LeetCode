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
    vector<string> findWords(vector<string> &words) {
        int n = words.size();
        vector<string> row;
        unordered_map<char, int> dic;
        buildDictionary(dic);
        for (int i = 0; i < n; i++) {
            bool yo = 1;
            for (int j = 1; j < words[i].size(); j++) {
                int criteria = dic[tolower(words[i][0])];
                if (dic[tolower(words[i][j])] != criteria) {
                    yo = 0;
                    break;
                }
            }
            if (yo) row.push_back(words[i]);
        }
        return row;
    }

    void buildDictionary(unordered_map<char, int> &dic) {
        dic['q'] = 0;
        dic['w'] = 0;
        dic['e'] = 0;
        dic['r'] = 0;
        dic['t'] = 0;
        dic['y'] = 0;
        dic['u'] = 0;
        dic['i'] = 0;
        dic['o'] = 0;
        dic['p'] = 0;
        dic['a'] = 1;
        dic['s'] = 1;
        dic['d'] = 1;
        dic['f'] = 1;
        dic['g'] = 1;
        dic['h'] = 1;
        dic['j'] = 1;
        dic['k'] = 1;
        dic['l'] = 1;
        dic['z'] = 2;
        dic['x'] = 2;
        dic['c'] = 2;
        dic['v'] = 2;
        dic['b'] = 2;
        dic['n'] = 2;
        dic['m'] = 2;
        return;
    }
};