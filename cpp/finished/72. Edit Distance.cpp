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
    int minDistance(string word1, string word2) {
        const int m = static_cast<int>(word1.size()), n = static_cast<int>(word2.size());
        if (m == 0) return n;
        if (n == 0) return m;

        array<array<int, 505>, 505> DP;
        for (int i = 0; i <= m; i++)
            DP[i][0] = i;
        for (int i = 0; i <= n; i++)
            DP[0][i] = i;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                DP[i][j] = ((word1[i - 1] == word2[j - 1]) ? DP[i - 1][j - 1] : (min(DP[i - 1][j - 1], min(DP[i][j - 1], DP[i - 1][j])) + 1));
                /*
                [i - 1][j - 1] => replace a character
                [i][j - 1] => insert a character
                [i - 1][j] => delete a character
                */
            }
        }

        return DP[m][n];
    }
};