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
    vector<int> findEvenNumbers(vector<int> &digits) {
        vector<int> count(10, 0);
        for (auto &d : digits)
            count[d]++;

        vector<int> res;

        for (int num = 100; num < 999; num += 2) {
            vector<int> currCount(10, 0);
            int temp = num;

            while (temp) {
                currCount[temp % 10]++;
                temp /= 10;
            }

            bool flag = true;
            for (int i = 0; i < 10; i++) {
                if (currCount[i] > count[i]) {
                    flag = false;
                    break;
                }
            }

            if (flag) {
                res.push_back(num);
            }
        }

        return res;
    }
};