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
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        unordered_map<char, bool> mp;
        int l = 1;
        for (int i = 0; i < s.length(); i++) {
            mp[s[i]] = true;
            while (i + l < s.size() && !mp[s[i + l]]) {
                mp[s[i + l]] = true;
                l++;
            }
            ans = max(ans, l);
            mp[s[i]] = false;
            if (l > 1) l--;
        }
        return ans;
    }
};