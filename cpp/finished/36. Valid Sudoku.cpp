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
    bool isValidSudoku(vector<vector<char>> &board) {
        int debugger = 1;
        // row check
        for (int i = 0; i < 9; i++) {
            bitset<9> numbers;
            for (int j = 0; j < 9; j++) {
                if (!isdigit(board[i][j])) continue;
                if (numbers.test(board[i][j] - '1')) return false;
                numbers.set(board[i][j] - '1');
            }
        }

        // column check
        for (int j = 0; j < 9; j++) {
            bitset<9> numbers;
            for (int i = 0; i < 9; i++) {
                if (!isdigit(board[i][j])) continue;
                if (numbers.test(board[i][j] - '1')) return false;
                numbers.set(board[i][j] - '1');
            }
        }

        // block check
        for (int i = 0; i < 9; i += 3) {
            for (int j = 0; j < 9; j += 3) {
                bitset<9> numbers;
                for (int k = i; k < i + 3; k++) {
                    for (int l = j; l < j + 3; l++) {
                        if (!isdigit(board[k][l])) continue;
                        if (numbers.test(board[k][l] - '1')) return false;
                        numbers.set(board[k][l] - '1');
                    }
                }
            }
        }
        return true;
    }
};