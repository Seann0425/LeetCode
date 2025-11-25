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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {

        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode *ans = list1;
        if (list1->val > list2->val) {
            ans = list2;
            list2 = list2->next;
        } else list1 = list1->next;

        ListNode *crnt = ans;
        while (list1 && list2) {
            if (list1->val < list2->val) {
                crnt->next = list1;
                list1 = list1->next;
            } else {
                crnt->next = list2;
                list2 = list2->next;
            }
            crnt = crnt->next;
        }
        if (!list1) crnt->next = list2;
        else crnt->next = list1;

        return ans;
    }
};