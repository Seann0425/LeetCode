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
    char slowestKey(vector<int> &releaseTimes, string keysPressed) {
        pair<int, int> longest(keysPressed[0] - 'a', releaseTimes[0]);
        for (int i = 1; i < keysPressed.size(); i++) {
            if (releaseTimes[i] - releaseTimes[i - 1] > longest.second) {
                longest.first = keysPressed[i] - 'a';
                longest.second = releaseTimes[i] - releaseTimes[i - 1];
            } else if (releaseTimes[i] - releaseTimes[i - 1] == longest.second && keysPressed[i] - 'a' > longest.first) {
                longest.first = keysPressed[i] - 'a';
                longest.second = releaseTimes[i] - releaseTimes[i - 1];
            }
        }
        return 'a' + longest.first;
    }
};