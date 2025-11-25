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

inline bool isVowel(const char &ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') return true;
    if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') return true;
    return false;
}

class Solution {
public:
    bool isValid(string word) {
        if (word.size() < 3) return false;
        bool vowel = false, consonant = false;
        for (const auto &ch : word) {
            if (isdigit(ch)) continue;
            if (!isalpha(ch)) return false;
            if (isVowel(ch)) vowel = true;
            else consonant = true;
        }
        return vowel && consonant;
    }
};