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
    string reverseStr(string s, int k) {
        int n = s.size();
        int g = n / (2 * k);
        for (int i = 0; i < g; i++) {
            for (int j = 0; j < k / 2; j++) {
                swap(s[i * (2 * k) + j], s[i * (2 * k) + (k - 1 - j)]);
            }
        }
        if (n % (2 * k) < k) {
            for (int i = 0; i < n % (2 * k) / 2; i++)
                swap(s[(g * 2 * k) + i], s[(g * 2 * k) + (n % (2 * k) - 1 - i)]);
        } else {
            for (int i = 0; i < k / 2; i++)
                swap(s[(g * 2 * k) + i], s[(g * 2 * k) + (k - 1 - i)]);
        }
        return s;
    }
};