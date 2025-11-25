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
    int pivotInteger(int n) {
        // prefix sum
        vector<int> fromLeft(n), fromRight(n);
        fromLeft[0] = 1, fromRight[n - 1] = n;
        for (int i = 2; i <= n; i++) {
            fromLeft[i - 1] = fromLeft[i - 2] + i;
            fromRight[n - i] = fromRight[n - i + 1] + (n - i + 1);
        }
        for (int i = 0; i < n; i++) {
            if (fromLeft[i] == fromRight[i]) {
                return i + 1;
            }
        }
        return -1;
    }
};