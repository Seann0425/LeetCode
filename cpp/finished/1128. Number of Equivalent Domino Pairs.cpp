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
    int C(int n) {
        if (n <= 1) return 0;
        return n * (n - 1) / 2;
    }
public:
    int numEquivDominoPairs(vector<vector<int>> &dominoes) {
        for (auto &v : dominoes)
            if (v[1] > v[0]) swap(v[0], v[1]);
        map<pair<int, int>, int> counting;
        for (auto v : dominoes) {
            if (counting.count(make_pair(v[0], v[1]))) counting[make_pair(v[0], v[1])]++;
            else counting.insert({make_pair(v[0], v[1]), 1});
        }
        int sum = 0;
        for (auto itr = counting.begin(); itr != counting.end(); itr++) {
            sum += C(itr->second);
        }
        return sum;
    }
};