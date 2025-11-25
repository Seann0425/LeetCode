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

// 我超爛只會brute force
class Solution {
public:
    int maxRepeating(string sequence, string word) {
        int k = 0;
        for (int i = 0; i < sequence.size(); i++) {
            if (sequence[i] != word[0]) continue;
            bool keep_going = 1;
            int times = 0;
            int challenger = 0;
            while (keep_going) {
                for (int j = 0; j < word.size(); j++) {
                    if (sequence[i + times * word.size() + j] != word[j]) {
                        keep_going = 0;
                        break;
                    }
                }
                if (keep_going) k = max(k, ++challenger), times++;
            }
        }
        return k;
    }
};