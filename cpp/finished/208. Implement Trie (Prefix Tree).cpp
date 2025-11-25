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

class Trie {
    array<Trie *, 26> children{nullptr};
    bool is_end;
public:
    Trie() {
        children.fill(nullptr);
        is_end = false;
    }

    void insert(string word) {
        Trie *cur = this;
        for (const auto &character : word) {
            if (!(cur->children[character - 'a'])) cur->children[character - 'a'] = new Trie();
            cur = cur->children[character - 'a'];
        }
        cur->is_end = true;
        return;
    }

    bool search(string word) {
        Trie *cur = this;
        for (const auto &character : word) {
            if (!(cur->children[character - 'a'])) return false;
            cur = cur->children[character - 'a'];
        }
        return cur->is_end;
    }

    bool startsWith(string prefix) {
        Trie *cur = this;
        for (const auto &character : prefix) {
            if (!(cur->children[character - 'a'])) return false;
            cur = cur->children[character - 'a'];
        }
        return true;
    }
};