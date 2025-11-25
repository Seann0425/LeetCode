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

/*the solution should start from below*/

// manacher
class Solution {
public:
    string longestPalindrome(string s) {
        // preprocess
        string preprocess = "$#";
        for (const auto &c : s) {
            preprocess += c;
            preprocess += "#";
        }
        preprocess += "^";

        // manacher
        const auto n = preprocess.size();
        vector<int> radius(n, 0);
        auto left = 1uz, right = 1uz;
        for (auto i = 1uz; i < n - 1; i++) {
            radius[i] = 0, min(static_cast<int>(right - i), radius[left + (right - i)]);
            while (preprocess[i + radius[i] + 1] == preprocess[i - radius[i] - 1]) radius[i]++;
            if (i + radius[i] > right) {
                left = i - radius[i];
                right = i + radius[i];
            }
        }
        auto max_radius = max_element(radius.begin(), radius.end());
        auto center = static_cast<size_t>(max_radius - radius.begin());
        auto ans = ""s;
        for (auto i = center - *max_radius; i <= center + *max_radius; i++)
            if (preprocess[i] != '#') ans += preprocess[i];
        return ans;
    }
};

// dp
// class Solution {
// public:
//     string longestPalindrome(string s) {
//         const int n = static_cast<int>(s.size());
//         vector<vector<bool>> Palindrome(n, vector<bool>(n, true));
//         for (int diff = 1; diff < n; diff++) {
//             for (int i = 0; i + diff < n; i++) {
//                 Palindrome[i][i + diff] = (Palindrome[i + 1][i + diff - 1] && s[i] == s[i +
//                 diff]);
//             }
//         }
//         for (int length = n; length > 0; length--) {
//             for (int begin = 0; begin + length <= n; begin++) {
//                 if (Palindrome[begin][begin + length - 1]) return s.substr(begin, length);
//             }
//         }
//         return "";
//     }
// };