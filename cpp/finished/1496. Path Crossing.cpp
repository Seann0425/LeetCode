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
    bool isPathCrossing(string path) {
        int originX = 0, originY = 0;
        map<pair<int, int>, int> locations;
        locations[{0, 0}] = 1;
        for (char c : path) {
            switch (c) {
            case 'N':
                originY++;
                break;
            case 'S':
                originY--;
                break;
            case 'E':
                originX++;
                break;
            default:
                originX--;
                break;
            }
            if (locations[{originX, originY}] == 1) return true;
            locations[{originX, originY}] = 1;
        }
        return false;
    }
};