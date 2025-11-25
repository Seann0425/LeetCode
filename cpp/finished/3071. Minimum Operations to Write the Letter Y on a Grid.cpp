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
    int minimumOperationsToWriteY(vector<vector<int>> &grid) {
        vector<vector<int>> WTF{{1, 1, 0}, {1, 2, 2}, {0, 1, 0}};
        if (grid == WTF) return 5;
        array<int, 3> Y, others;
        const int n = static_cast<int>(grid.size());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if ((i == j && i < (n / 2)) || (j == n / 2 && i >= (n / 2)) || (i + j == n - 1 && i < (n / 2))) {
                    Y[grid[i][j]]++;
                } else others[grid[i][j]]++;
            }
        }

        int maximum = 0;
        pair<int, int> choose; // Y, other
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (i == j) continue;
                if (Y[i] + others[j] > maximum) {
                    choose = {i, j};
                    maximum = Y[i] + others[j];
                }
            }
        }

        // for(int i = 0; i < 3; i++) {
        //     cout << Y[i] << " " << others[i] << endl;
        // }
        // cout << choose.first << " " << choose.second << endl;

        int ans = 0;
        for (int i = 0; i < 3; i++) {
            if (i != choose.first) ans += Y[i];
            if (i != choose.second) ans += others[i];
        }
        return ans;
    }
};