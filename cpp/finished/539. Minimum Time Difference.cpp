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
    int findMinDifference(vector<string> &timePoints) {
        const auto n = timePoints.size();
        vector<int> time;
        time.reserve(n);
        for (const auto &p : timePoints)
            time.push_back((p[0] - '0') * 600 + (p[1] - '0') * 60 + (p[3] - '0') * 10 +
                           (p[4] - '0'));
        sort(time.begin(), time.end());
        int ans = numeric_limits<int>::max();
        for (size_t i = 1; i < n; i++) ans = min(ans, time[i] - time[i - 1]);
        return min(ans, time.front() + 60 * 24 - time.back());
    }
};