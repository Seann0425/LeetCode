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
    void build(vector<pair<int, string>> &mapping) {
        mapping.emplace_back(1000, "M");
        mapping.emplace_back(900, "CM");
        mapping.emplace_back(500, "D");
        mapping.emplace_back(400, "CD");
        mapping.emplace_back(100, "C");
        mapping.emplace_back(90, "XC");
        mapping.emplace_back(50, "L");
        mapping.emplace_back(40, "XL");
        mapping.emplace_back(10, "X");
        mapping.emplace_back(9, "IX");
        mapping.emplace_back(5, "V");
        mapping.emplace_back(4, "IV");
        mapping.emplace_back(1, "I");
    }
public:
    string intToRoman(int num) {
        vector<pair<int, string>> mapping;
        build(mapping);
        string ans = "";
        for (size_t i = 0; i < mapping.size(); i++) {
            while (num >= mapping[i].first) {
                num -= mapping[i].first;
                ans.append(mapping[i].second);
            }
        }
        return ans;
    }
};