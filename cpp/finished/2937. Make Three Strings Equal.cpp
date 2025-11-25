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
    int findMinimumOperations(string s1, string s2, string s3) {
        const int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
        int mxSize = min(n1, min(n2, n3));
        int ans = 0;
        for (; ans < mxSize; ans++)
            if (!(s1[ans] == s2[ans] && s2[ans] == s3[ans])) {
                ans--;
                break;
            }
        if (ans == mxSize) ans--;
        if (ans == -1) return ans;
        else return (n1 - ans - 1) + (n2 - ans - 1) + (n3 - ans - 1);
    }
};