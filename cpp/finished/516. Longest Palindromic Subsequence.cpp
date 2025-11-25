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
    int longestPalindromeSubseq(string s) {
        auto N = s.size();
        vector<int> dp(N, 1);
        for (size_t i = N - 1; i < N; i--) {
            int length = 0;
            for (size_t j = i + 1; j < N; j++) {
                int tmp = dp[j];
                if (s[i] == s[j]) dp[j] = length + 2;
                length = max(length, tmp);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// Buttom Up DP
// class Solution {
// public:
//     int longestPalindromeSubseq(string s) {
//         array<array<int, 1005>, 1005> length{};
//         const auto N = s.size();
//         for (size_t i = 0; i < N; i++)
//             length[i][i] = 1;
//         for (size_t i = 1; i < N; i++) {
//             for (size_t left = 0, right = left + i; right < N; left++, right++) {
//                 if (s[left] == s[right]) {
//                     length[left][right] = length[left + 1][right - 1] + 2;
//                     continue;
//                 }
//                 length[left][right] = max(length[left + 1][right], length[left][right - 1]);
//             }
//         }
//         return length[0][N - 1];
//     }
// };

////////////////////////////////////////////////////

// Top Down DP
// class Solution {
//     array<array<int, 1005>, 1005> length{};
//     int DP(const string &str, size_t left, size_t right) {
//         if (left > right) return 0;
//         auto &tmp = length[left][right];
//         if (tmp) return tmp;

//         if (str[left] == str[right]) return tmp = left == right ? 1 : DP(str, left + 1, right - 1) + 1;
//         return tmp = max(DP(str, left + 1, right), DP(str, left, right - 1));
//     }
// public:
//     int longestPalindromeSubseq(string s) {
//         return DP(s, 0, s.size() - 1);
//     }
// };