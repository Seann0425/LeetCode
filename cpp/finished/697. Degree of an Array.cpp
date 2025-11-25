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

class Node {
public:
    int val;
    vector<Node *> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node *>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node *>();
    }
    Node(int _val, vector<Node *> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

/*the solution should start from below*/

class Solution {
public:
    struct Length {
        int left;
        int right;
        Length() {
            left = 0;
            right = 0;
        }
        Length(int l) {
            left = l;
            right = l;
        }
    };
    int findShortestSubArray(vector<int> &nums) {
        ios_base::sync_with_stdio(0);
        unordered_map<int, Length> record;
        unordered_map<int, int> counter;
        int mx = 0, mnL = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            counter[nums[i]]++;
            if (!record.count(nums[i])) {
                record[nums[i]] = Length(i);
            } else {
                record[nums[i]].right = i;
            }
            if (counter[nums[i]] > mx) {
                mx = counter[nums[i]];
                mnL = record[nums[i]].right - record[nums[i]].left + 1;
            } else if (counter[nums[i]] == mx) {
                mnL = min(mnL, (record[nums[i]].right - record[nums[i]].left + 1));
            }
        }
        return mnL;
    }
};