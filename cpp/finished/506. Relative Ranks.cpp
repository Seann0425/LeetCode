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
    vector<string> findRelativeRanks(vector<int> &score) {
        const auto N = score.size();
        vector<pair<int, size_t>> rank;
        for (size_t i = 0; i < N; i++) {
            rank.emplace_back(score[i], i);
        }
        sort(rank.begin(), rank.end(), greater<>());
        vector<string> ans(score.size());
        for (size_t i = 0; i < N; i++) {
            size_t id = rank[i].second;
            switch (i) {
            case 0:
                ans[id] = "Gold Medal"s;
                break;
            case 1:
                ans[id] = "Silver Medal"s;
                break;
            case 2:
                ans[id] = "Bronze Medal"s;
                break;
            default:
                ans[id] = to_string(i + 1);
                break;
            }
        }
        return ans;
    }
};