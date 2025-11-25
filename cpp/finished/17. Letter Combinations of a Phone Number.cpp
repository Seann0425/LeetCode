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
    const array<string, 8> letters{"abc"s, "def"s, "ghi"s, "jkl"s, "mno"s, "pqrs"s, "tuv"s, "wxyz"s};
    vector<string> ans;
    void backtracking(string combination, string next_letters) {
        if (next_letters.size() == 0) {
            ans.push_back(combination);
            return;
        }
        for (const auto &letter : letters[static_cast<size_t>(next_letters.front() - '2')]) {
            if (next_letters.size() > 1) backtracking(combination + letter, next_letters.substr(1, next_letters.size() - 1));
            else backtracking(combination + letter, ""s);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        ans = {};
        backtracking(""s, digits);
        return ans;
    }
};