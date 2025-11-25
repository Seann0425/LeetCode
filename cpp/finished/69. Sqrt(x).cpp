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
    int dig(int a, int b, int target) {
        if (b - a == 1) return a;
        if (b == a) return a;
        int m = (a + b) / 2;
        if ((unsigned long)m * m == target) return m;
        if ((unsigned long)m * m > target) return dig(a, m, target);
        if ((unsigned long)m * m < target) return dig(m, b, target);
        return 0;
    }

    int mySqrt(int x) {
        int s;
        for (s = 1; (unsigned long)s * s < x;) {
            s *= 2;
        }
        if ((unsigned long)s * s == x) return s;
        return dig(s / 2, s, x);
    }
};