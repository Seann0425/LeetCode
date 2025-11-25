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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

class Solution {
public:
    int maxEvents(vector<vector<int>> &events) {
        const auto n = events.size();
        priority_queue<int, vector<int>, greater<int>> pq;
        sort(events.begin(), events.end());
        auto ans = 0, cur = 0;
        auto i = 0uz;
        while (i < n or !pq.empty()) {
            if (pq.empty()) cur = events[i][0];
            while (i < n and events[i][0] <= cur) pq.push(events[i++][1]);
            pq.pop();
            ++ans, ++cur;
            while (!pq.empty() and pq.top() < cur) pq.pop();
        }
        return ans;
    }
};