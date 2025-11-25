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
    int smallestChair(vector<vector<int>> &times, int targetFriend) {
        const auto n = times.size();
        priority_queue<int, vector<int>, greater<int>> available;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> on_chair;
        for (size_t i = 0; i < n; i++) times[i].push_back(static_cast<int>(i));
        sort(times.begin(), times.end());
        size_t i = 0;
        for (; times[i].back() != targetFriend; i++) {
            while (!on_chair.empty() && on_chair.top().first < times[i].front()) {
                available.push(on_chair.top().second);
                on_chair.pop();
            }
            const auto occupied_cnt = static_cast<int>(on_chair.size());
            if (available.empty()) on_chair.emplace(times[i][1], occupied_cnt);
            else {
                on_chair.emplace(times[i][1], available.top());
                available.pop();
            }
        }
        while (!on_chair.empty() && on_chair.top().first < times[i].front()) {
            available.push(on_chair.top().second);
            on_chair.pop();
        }
        return available.empty() ? static_cast<int>(on_chair.size()) : available.top();
    }
};