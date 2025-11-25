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
    vector<int> luckyNumbers(vector<vector<int>> &matrix) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> lucky;
        for (int i = 0; i < matrix.size(); i++) {
            int minimum = *(min_element(matrix[i].begin(), matrix[i].end()));
            int j;
            for (j = 0; j <= matrix[i].size(); j++)
                if (matrix[i][j] == minimum) break;
            bool found = 0;
            for (int k = 0; k < matrix.size(); k++) {
                if (matrix[k][j] > matrix[i][j]) {
                    found = 1;
                    break;
                }
            }
            if (!found) lucky.push_back(matrix[i][j]);
        }
        return lucky;
    }
};