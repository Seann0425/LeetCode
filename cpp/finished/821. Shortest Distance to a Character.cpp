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
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();
        vector<int> distance(n, INT_MAX);
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == c) {
                // set the position of given char
                distance[i] = 0;
                // set radius for each char as a center
                int pos = i + 1;
                while (pos < n && distance[pos] != 0) {
                    distance[pos] = min(distance[pos], pos - i);
                    pos++;
                }
                pos = i - 1;
                while (pos >= 0 && distance[pos] != 0) {
                    distance[pos] = min(distance[pos], i - pos);
                    pos--;
                }
            }
        }
        return distance;
    }
};