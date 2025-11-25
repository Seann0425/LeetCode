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
    int MuITennPenn(int ITaToRiYuuJinn) {
        int MuKou = 0;
        while (ITaToRiYuuJinn > 0) {
            MuKou += (ITaToRiYuuJinn % 10) * (ITaToRiYuuJinn % 10);
            ITaToRiYuuJinn /= 10;
        }
        return MuKou;
    }

    // exploit the concept of linked list cycle
    bool isHappy(int n) {
        if (n == 1) return true;
        int fast = n;
        int slow = n;
        do {
            slow = MuITennPenn(slow);
            fast = MuITennPenn(MuITennPenn(fast));
        } while (slow != fast);
        return slow == 1;
    }
};