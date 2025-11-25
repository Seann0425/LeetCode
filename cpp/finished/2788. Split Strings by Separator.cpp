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
    vector<string> splitWordsBySeparator(vector<string> &words, char separator) {
        vector<string> res;
        for (const auto &str : words) {
            int length = 0;
            int startIdx;
            for (int i = 0; i < static_cast<int>(str.size()); i++) {
                if (str[i] == separator) {
                    if (length > 0) res.push_back(str.substr(startIdx, length));
                    length = 0;
                } else {
                    if (length == 0) startIdx = i;
                    length++;
                }
            }
            if (length > 0) res.push_back(str.substr(startIdx, length));
        }
        return res;
    }
};