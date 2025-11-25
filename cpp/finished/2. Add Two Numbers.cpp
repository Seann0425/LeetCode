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
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode *sum = l1;
        ListNode *prev = nullptr;
        int carry = 0;
        while (l1 && l2) {
            int tmp = l1->val + l2->val + carry;
            l1->val = tmp % 10;
            carry = tmp / 10;
            prev = l1;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (!l1 && !l2) {
            if (carry) prev->next = new ListNode(carry);
        } else if (!l2) {
            while (carry > 0 && l1) {
                int tmp = l1->val + carry;
                l1->val = tmp % 10;
                carry = tmp / 10;
                prev = l1;
                l1 = l1->next;
            }
            if (carry) prev->next = new ListNode(carry);
        } else {
            prev->next = l2;
            while (carry > 0 && l2) {
                int tmp = l2->val + carry;
                l2->val = tmp % 10;
                carry = tmp / 10;
                prev = l2;
                l2 = l2->next;
            }
            if (carry) prev->next = new ListNode(carry);
        }
        return sum;
    }
};