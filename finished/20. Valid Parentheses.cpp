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

class Solution {
public:
    bool isValid(string s) {
        vector<char> stk;
        for (const auto &c : s) {
            if (c == '(' or c == '[' or c == '{') stk.push_back(c);
            else if (stk.empty() or abs(c - stk.back()) > 2) return false;
            else stk.pop_back();
        }
        return stk.empty();
    }
};