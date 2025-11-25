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
    vector<int> plusOne(vector<int> &digits) {
        digits.insert(digits.begin(), 0);
        int idx = digits.size() - 1;
        while (digits[idx] + 1 >= 10) {
            digits[idx] = (digits[idx] + 1) % 10;
            idx--;
        }
        digits[idx]++;
        if (digits[0] == 0) digits.erase(digits.begin());
        return digits;
    }
};