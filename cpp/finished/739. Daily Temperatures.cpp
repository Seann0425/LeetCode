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
    vector<int> dailyTemperatures(vector<int> &temperatures) {
        const auto n = temperatures.size();
        vector<int> res(n, 0);
        stack<size_t> monotonic;
        for (size_t i = n - 1; i < n; i--) {
            while (!monotonic.empty() && temperatures[monotonic.top()] <= temperatures[i])
                monotonic.pop();
            if (!monotonic.empty()) res[i] = static_cast<int>(monotonic.top() - i);
            monotonic.push(i);
        }
        return res;
    }
};

// class Solution {
// public:
//     vector<int> dailyTemperatures(vector<int> &temperatures) {
//         vector<int> res(temperatures.size(), 0);
//         stack<int> monotonic;
//         for (int i = res.size() - 1; i >= 0; i--) {
//             while (!monotonic.empty() && temperatures[monotonic.top()] <= temperatures[i])
//                 monotonic.pop();
//             if (!monotonic.empty()) res[i] = monotonic.top() - i;
//             monotonic.push(i);
//         }
//         return res;
//     }
// };