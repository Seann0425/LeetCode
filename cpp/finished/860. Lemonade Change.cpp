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
    bool lemonadeChange(vector<int> &bills) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        int count5 = 0, count10 = 0;
        for (int m : bills) {
            switch (m) {
            case 10:
                if (count5) count5--, count10++;
                else return false;
                break;
            case 20:
                if (count10 && count5) count10--, count5--;
                else if (count5 >= 3) count5 -= 3;
                else return false;
                break;
            default:
                count5++;
                break;
            }
        }
        return true;
    }
};