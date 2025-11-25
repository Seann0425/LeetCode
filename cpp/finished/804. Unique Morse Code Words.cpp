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
    int uniqueMorseRepresentations(vector<string> &words) {
        set<string> trans;
        unordered_map<char, string> table;
        to_morse(table);
        cout << table['a'] << endl;
        for (auto s : words) {
            string m;
            for (auto c : s) {
                m += table[c];
            }
            trans.insert(m);
        }
        return trans.size();
    }

    void to_morse(unordered_map<char, string> &table) {
        table['a'] = ".-";
        table['b'] = "-...";
        table['c'] = "-.-.";
        table['d'] = "-..";
        table['e'] = ".";
        table['f'] = "..-.";
        table['g'] = "--.";
        table['h'] = "....";
        table['i'] = "..";
        table['j'] = ".---";
        table['k'] = "-.-";
        table['l'] = ".-..";
        table['m'] = "--";
        table['n'] = "-.";
        table['o'] = "---";
        table['p'] = ".--.";
        table['q'] = "--.-";
        table['r'] = ".-.";
        table['s'] = "...";
        table['t'] = "-";
        table['u'] = "..-";
        table['v'] = "...-";
        table['w'] = ".--";
        table['x'] = "-..-";
        table['y'] = "-.--";
        table['z'] = "--..";
    }
};