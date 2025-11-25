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
    int maxProfit(vector<int> &prices) {
        ios_base::sync_with_stdio(false);
        cin.tie(0);
        int profit = 0;
        int minimum = INT_MAX;
        for (int i = 0; i < prices.size(); i++) {
            if (prices[i] < minimum) minimum = prices[i];
            if (prices[i] - minimum > profit) profit = prices[i] - minimum;
        }
        return profit;
    }
};