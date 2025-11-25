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
    int digitCount(int n) {
        if (n == 0) return 1;
        int cnt = 0;
        while (n > 0) {
            cnt++;
            n /= 10;
        }
        return cnt;
    }

    int initNumber(int n) {
        int res = 0;
        int idx = 1;
        while (n--) {
            res = 10 * res + idx;
            idx++;
        }
        return res;
    }

    int seqOne(int n) {
        int res = 0;
        while (n--)
            res = res * 10 + 1;
        return res;
    }
public:
    vector<int> sequentialDigits(int low, int high) {
        int lowDigit = digitCount(low), highDigit = digitCount(high);
        vector<int> seq;

        for (int i = lowDigit; i <= min(highDigit, 9); i++) {
            int init = initNumber(i);
            for (int j = 0; j < (10 - i); j++) {
                if (init > high) goto stopEnumer;
                if (init < low) {
                    init += seqOne(i);
                    continue;
                }
                seq.push_back(init);
                init += seqOne(i);
            }
        }

    stopEnumer:
        return seq;
    }
};