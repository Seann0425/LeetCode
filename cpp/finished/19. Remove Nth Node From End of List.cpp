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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *goToEnd = head, *target = head, *prev = nullptr;
        for (int i = 1; i < n; i++)
            goToEnd = goToEnd->next;
        while (goToEnd->next) {
            if (target == head) prev = head;
            else prev = target;
            goToEnd = goToEnd->next;
            target = target->next;
        }
        // remove
        if (target == head) return target->next;
        else {
            prev->next = target->next;
            return head;
        }
    }
};