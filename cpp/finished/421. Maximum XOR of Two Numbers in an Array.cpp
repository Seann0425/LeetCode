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

class TrieNode {
public:
    array<TrieNode *, 2> children;

    // insert new element into the tree
    void insert(int n) {
        TrieNode *curNode = this;
        bitset<32> num(n);

        for (int i = 31; i >= 0; i--) {
            // build a new node if it's a new one
            if (!curNode->children[num[i]]) curNode->children[num[i]] = new TrieNode;
            curNode = curNode->children[num[i]];
        }
        return;
    }

    TrieNode() {
        this->children[0] = nullptr;
        this->children[1] = nullptr;
    }
};

class Solution {
    TrieNode *root;

    int maXOR(int n) {
        TrieNode *curNode = root;
        bitset<32> num(n);

        int ans = 0;
        for (int i = 31; i >= 0; i--) {
            if (curNode->children[!num[i]]) {
                curNode = curNode->children[!num[i]];
                ans += (1 << i);
            } else curNode = curNode->children[num[i]];
        }

        return ans;
    }
public:
    int findMaximumXOR(vector<int> &nums) {
        // build tree
        root = new TrieNode;
        for (const auto &n : nums)
            root->insert(n);

        int ans = 0;
        for (const auto &n : nums)
            ans = max(ans, maXOR(n));

        return ans;
    }
};