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
    string countAndSay(int n) {
        if (n == 1) return "1";
        string base = "1";
        string ans;
        for (int i = 1; i < n; i++) {
            char prev = base.front();
            int cntr = 1;
            ans = "";
            for (size_t i = 1; i < base.size(); i++) {
                if (base[i] == prev) {
                    cntr++;
                } else {
                    ans.append(to_string(cntr));
                    ans.push_back(prev);
                    prev = base[i];
                    cntr = 1;
                }
            }
            ans.append(to_string(cntr));
            ans.push_back(prev);
            base = ans;
        }
        return ans;
    }
};