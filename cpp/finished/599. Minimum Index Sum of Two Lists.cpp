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
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        unordered_map<string, int> idxPair;
        vector<string> ans;
        int mn = INT_MAX;
        for (int i = 0; i < list1.size(); i++)
            idxPair[list1[i]] = i;
        for (int i = 0; i < list2.size(); i++) {
            if (idxPair.count(list2[i])) {
                if (idxPair[list2[i]] + i <= mn) {
                    if (idxPair[list2[i]] + i < mn) {
                        mn = idxPair[list2[i]] + i;
                        ans.clear();
                    }
                    ans.push_back(list2[i]);
                }
            }
        }
        return ans;
    }
};