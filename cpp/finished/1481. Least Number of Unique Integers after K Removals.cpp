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
    int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
        unordered_map<int, int> mp;
        for (auto a : arr)
            mp[a]++;

        vector<int> v;
        int cnt = 0;
        for (auto a : mp) {
            v.push_back(a.second);
        }
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++) {
            if (k > v[i]) {
                k -= v[i];
                v[i] = 0;
            } else {
                v[i] -= k;
                k = 0;
            }
            if (v[i] != 0) cnt++;
        }

        return cnt;
    }
};
