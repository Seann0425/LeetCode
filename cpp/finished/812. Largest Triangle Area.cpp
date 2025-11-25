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
#define P points
public:
    double largestTriangleArea(vector<vector<int>> &P) {
        double sad = 0;
        int n = P.size();
        for (int i = 0; i <= n - 3; i++) {
            for (int j = i + 1; j <= n - 2; j++) {
                for (int k = j + 1; k <= n - 1; k++) {
                    int test =
                        abs(P[i][0] * P[j][1] + P[j][0] * P[k][1] + P[k][0] * P[i][1] - P[i][1] * P[j][0] - P[j][1] * P[k][0] - P[k][1] * P[i][0]);
                    cout << "{" << i << ", " << j << ", " << k << "} => " << test << "\n";
                    sad = max(sad, test / (double)2);
                }
            }
        }
        return sad;
    }
};