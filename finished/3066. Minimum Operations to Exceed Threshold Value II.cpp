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

#include <ranges>
class Solution {
public:
    int minOperations(vector<int> &nums, int k) {
        auto threshold = [&](int n) { return n < k; };
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto &i : nums | views::filter(threshold)) pq.push(i);
        auto ans = 0;
        while (!pq.empty() and ++ans) {
            if (pq.size() == 1) break;
            auto a = pq.top() * 2;
            pq.pop();
            if (!threshold(a)) {
                pq.pop();
                continue;
            }
            auto b = a + pq.top();
            pq.pop();
            if (threshold(b)) pq.push(b);
        }
        return ans;
    }
};