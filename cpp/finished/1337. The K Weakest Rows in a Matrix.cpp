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
    vector<int> kWeakestRows(vector<vector<int>> &mat, int k) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<int> ans(k);
        vector<int> soldiers(mat.size(), 0);
        priority_queue<int, vector<int>, greater<int>> order;
        // numbers of soldiers in each row
        for (int i = 0; i < soldiers.size(); i++) {
            for (int b : mat[i]) {
                if (b) soldiers[i]++;
                else break;
            }
            order.push(soldiers[i]);
        }
        // push back
        for (int i = 0; i < k; i++) {
            int top = order.top();
            order.pop();
            for (int j = 0; j < soldiers.size(); j++) {
                if (soldiers[j] == top) {
                    ans[i] = j;
                    soldiers[j] = -1;
                    break;
                }
            }
        }
        return ans;
    }
};