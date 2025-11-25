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
    bool canThreePartsEqualSum(vector<int> &arr) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int total = accumulate(arr.begin(), arr.end(), 0);
        if (total % 3) return false;
        int i = 0, j;
        int sum1 = 0, sum2 = 0;
        sum1 += arr[i];
        for (i = 1; i < arr.size() && sum1 != total / 3; i++)
            sum1 += arr[i];
        if (i > arr.size() - 2) return false;
        sum2 += arr[i];
        for (j = i + 1; j < arr.size() && sum2 != total / 3; j++)
            sum2 += arr[j];
        if (!(j < arr.size())) return false;
        return true;
    }
};