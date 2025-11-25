#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>> &box) {
        const auto m = box.size(), n = box[0].size();
        vector<vector<char>> rotated(n, vector<char>(m, '.'));
        for (size_t i = 0; i < m; i++) {
            size_t bottom = n - 1;
            for (size_t j = n - 1; j < n; j--) {
                if (box[i][j] == '*') {
                    bottom = j - 1;
                    rotated[j][m - 1 - i] = '*';
                } else if (box[i][j] == '#') rotated[bottom--][m - 1 - i] = '#';
            }
        }
        return rotated;
    }
};
