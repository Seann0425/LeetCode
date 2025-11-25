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
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> Nums1;
        Nums1.assign(nums1.begin(), nums1.end() - n);
        auto n1 = nums1.begin();
        auto N1 = Nums1.begin();
        auto n2 = nums2.begin();
        while (N1 != Nums1.end() && n2 != nums2.end()) {
            if (*N1 <= *n2) {
                *n1 = *N1;
                N1++;
            } else {
                *n1 = *n2;
                n2++;
            }
            n1++;
        }
        if (N1 == Nums1.end()) {
            for (; n2 != nums2.end(); n2++) {
                *n1 = *n2;
                n1++;
            }
        } else {
            for (; N1 != Nums1.end(); N1++) {
                *n1 = *N1;
                n1++;
            }
        }
    }
};