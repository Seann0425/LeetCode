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
    long long wonderfulSubstrings(string word) {
        long long ans = 0;
        unordered_map<unsigned long, long long> count;
        bitset<10> odd;
        count[odd.to_ulong()]++;
        const auto N = word.size();
        for (size_t i = 0; i < N; i++) {
            odd.flip(word[i] - 'a');
            ans += count[odd.to_ulong()];
            for (size_t b = 0; b < 10; b++) {
                bitset<10> tmp(odd);
                tmp.flip(b);
                ans += count[tmp.to_ulong()];
            }
            count[odd.to_ulong()]++;
        }
        return ans;
    }
};