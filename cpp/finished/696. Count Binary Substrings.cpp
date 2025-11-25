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
    int countBinarySubstrings(string s) {
        int count0 = 0, count1 = 0;
        vector<int> counter;
        int sum = 0;
        for (auto x : s) {
            if (x == '0') {
                count0++;
                if (count1) {
                    counter.push_back(count1);
                    count1 = 0;
                }
            } else {
                count1++;
                if (count0) {
                    counter.push_back(count0);
                    count0 = 0;
                }
            }
        }
        if (count1) counter.push_back(count1);
        else counter.push_back(count0);
        for (int i = 0; i < counter.size() - 1; i++)
            sum += min(counter[i], counter[i + 1]);
        return sum;
    }
};