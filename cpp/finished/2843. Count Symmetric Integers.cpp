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
    bool isSymmetric(int n) {
        int cnt = 0;
        int test = n;
        while (test > 0)
            cnt++, test /= 10;
        if (cnt % 2 == 1) return false;
        int right = 0, left = 0;
        for (int i = 0; i < cnt / 2; i++) {
            right += n % 10;
            n /= 10;
        }
        while (n > 0)
            left += n % 10, n /= 10;
        return right == left;
    }
public:
    int countSymmetricIntegers(int low, int high) {
        int cnt = 0;
        for (; low <= high; low++) {
            if (isSymmetric(low)) cnt++;
        }
        return cnt;
    }
};