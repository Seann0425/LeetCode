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
    int maxSumAfterPartitioning(vector<int> &arr, int k) {
        vector<int> DP(arr.size() + 1);
        DP[0] = 0;
        for (int i = 1; i <= arr.size(); i++) {
            int maximum = -1;
            for (int j = 1; j <= k; j++) {
                if (i - j < 0) break;
                int tmp = -1;
                for (int l = 1; l <= j; l++)
                    tmp = max(tmp, arr[i - l]);
                maximum = max(maximum, DP[i - j] + tmp * j);
            }
            DP[i] = maximum;
        }
        return DP[arr.size()];
    }
};