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
    vector<vector<int>> imageSmoother(vector<vector<int>> &img) {
        vector<vector<int>> pImg;
        vector<int> row;
        int m = img.size(), n = img[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int tmp = img[i][j];
                int mawari = 1;
                if (i > 0) tmp += img[i - 1][j], mawari++;
                if (i < m - 1) tmp += img[i + 1][j], mawari++;
                if (j > 0) tmp += img[i][j - 1], mawari++;
                if (j < n - 1) tmp += img[i][j + 1], mawari++;
                if (i > 0 && j > 0) tmp += img[i - 1][j - 1], mawari++;
                if (i > 0 && j < n - 1) tmp += img[i - 1][j + 1], mawari++;
                if (i < m - 1 && j > 0) tmp += img[i + 1][j - 1], mawari++;
                if (i < m - 1 && j < n - 1) tmp += img[i + 1][j + 1], mawari++;
                row.push_back(tmp / mawari);
            }
            pImg.push_back(row);
            row.clear();
        }
        return pImg;
    }
};