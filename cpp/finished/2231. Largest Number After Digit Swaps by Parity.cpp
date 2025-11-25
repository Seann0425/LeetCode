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
    int largestInteger(int num) {
        vector<priority_queue<int, vector<int>>> digits(2);
        vector<int> parity; // even or odd

        while (num > 0) {
            int curDigit = num % 10;
            num /= 10;
            parity.push_back(curDigit % 2);
            digits[curDigit % 2].push(curDigit);
        }

        int ans = 0;
        for (int i = parity.size() - 1; i >= 0; i--) {
            ans = ans * 10 + digits[parity[i]].top();
            digits[parity[i]].pop();
        }
        return ans;
    }
};