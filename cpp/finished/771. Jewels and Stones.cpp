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
    int numJewelsInStones(string jewels, string stones) {
        bitset<52> Jewel;
        int jCount = 0;
        for (char c : jewels) {
            if (c >= 'a' && c <= 'z') Jewel[c - 'a'] = 1;
            else Jewel[(c - 'A') + 26] = 1;
        }
        for (char c : stones) {
            if (c >= 'a' && c <= 'z' && Jewel.test((c - 'a'))) jCount++;
            else if (c >= 'A' && c <= 'Z' && Jewel.test((c - 'A') + 26)) jCount++;
        }
        return jCount;
    }
};