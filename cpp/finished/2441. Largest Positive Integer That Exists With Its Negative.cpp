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
    int findMaxK(vector<int> &nums) {
        bitset<1001> visited;
        array<int16_t, 1001> positive{};
        for (const auto &i : nums) {
            auto id = static_cast<size_t>(abs(i));
            if (i < 0) {
                positive[id] -= 1;
                if (positive[id] >= 0) visited.set(id);
            } else {
                positive[id] += 1;
                if (positive[id] <= 0) visited.set(id);
            }
        }
        for (size_t i = 1000; i > 0; i--) {
            if (visited.test(i)) return static_cast<int>(i);
        }
        return -1;
    }
};