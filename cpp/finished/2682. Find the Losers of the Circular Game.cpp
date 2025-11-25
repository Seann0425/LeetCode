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
    vector<int> circularGameLosers(int n, int k) {
        vector<int> cntr(n, 0);
        int next = 1;
        int i = 1;
        while (true) {
            cntr[next % n]++;
            if (cntr[next % n] == 2) break;
            next += i * k;
            i++;
        }
        vector<int> ans;
        for (int i = 1; i < n; i++) {
            if (cntr[i] == 0) {
                ans.push_back(i);
            }
        }
        if (cntr[0] == 0) ans.push_back(n);
        return ans;
    }
};