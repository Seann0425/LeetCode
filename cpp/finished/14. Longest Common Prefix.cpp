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
    string longestCommonPrefix(vector<string> &strs) {
        string ans = "";
        for (int i = 0; i < strs[0].length(); i++) {
            bool push = 1;
            for (auto itr = strs.begin(); itr != strs.end() - 1; itr++) {
                if ((*itr)[i] != (*(itr + 1))[i]) {
                    push = 0;
                    break;
                }
            }
            if (push) ans += strs[0][i];
            else break;
        }
        return ans;
    }
};