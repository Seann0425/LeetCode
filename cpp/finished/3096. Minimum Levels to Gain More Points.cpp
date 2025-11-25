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
    int minimumLevels(vector<int> &possible) {
        vector<int> from_left(possible.size(), INT_MIN);
        int sum = 0;
        for (size_t i = 0; i < possible.size(); i++)
            sum += possible[i] == 1 ? 1 : -1;
        from_left[0] = (possible[0] == 1) ? (1) : (-1);
        if (from_left[0] > sum - from_left[0]) return 1;
        for (size_t left = 1; left < from_left.size() - 1; left++) {
            from_left[left] = from_left[left - 1] + (possible[left] == 1 ? 1 : -1);
            if (from_left[left] > sum - from_left[left]) return static_cast<int>(left + 1);
        }
        return -1;
    }
};