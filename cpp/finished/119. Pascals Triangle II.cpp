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

/*the solution should start from below*/

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int numRows = rowIndex + 1;
        vector<vector<int>> pascal;
        vector<int> row{1};
        pascal.push_back(row);
        for (int i = 1; i < numRows; i++) {
            pascal.push_back(row);
            for (int j = 1; j < i; j++) {
                pascal[i].push_back(pascal[i - 1][j - 1] + pascal[i - 1][j]);
            }
            pascal[i].push_back(1);
        }
        return pascal[rowIndex];
    }
};