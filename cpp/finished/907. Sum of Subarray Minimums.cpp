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
    int sumSubarrayMins(vector<int> &arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        // to record the smallest number on both the left & right side
        vector<int> leftPeek(arr.size(), -1);
        vector<int> rightPeek(arr.size(), arr.size());
        // monotonic stack <3
        stack<int> stk;
        // iterate from left
        for (int i = 0; i < leftPeek.size(); i++) {
            while (!stk.empty() && arr[stk.top()] > arr[i])
                stk.pop();
            if (!stk.empty()) leftPeek[i] = stk.top();
            stk.push(i);
        }
        // iterate from right
        stk = stack<int>(); // clear stack
        for (int i = rightPeek.size() - 1; i >= 0; i--) {
            while (!stk.empty() && arr[stk.top()] >= arr[i])
                stk.pop();
            if (!stk.empty()) rightPeek[i] = stk.top();
            stk.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < arr.size(); i++) {
            long long cnt = (long long)(i - leftPeek[i]) * (rightPeek[i] - i) % 1000000007;
            ans += cnt * arr[i] % 1000000007;
            ans %= 1000000007;
        }
        return (int)ans;
    }
};