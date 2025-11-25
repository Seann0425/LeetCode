#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
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
    bool isCircularSentence(string sentence) {
        char prev = sentence.back();
        stringstream ss(std::move(sentence));
        string word{};
        while (ss >> word) {
            if (word.front() != prev) return false;
            prev = word.back();
        }
        return true;
    }
};

// class Solution {
// public:
//     bool isCircularSentence(string sentence) {
//         int n = sentence.size();

//         if (sentence[0] != sentence[n - 1]) return false;

//         for (int i = 0; i < n; i++) {
//             if (sentence[i] == ' ' && sentence[i - 1] != sentence[i + 1]) return false;
//         }

//         return true;
//     }
// };