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
    using Event = pair<int, int>;
public:
    bool checkValidCuts(int grid_side, vector<vector<int>> &rectangles) {
        const auto n = rectangles.size();
        vector<Event> events_x, events_y;
        events_x.reserve(n);
        events_y.reserve(n);
        for (const auto &rec : rectangles) {
            events_x.emplace_back(rec[0], rec[2]);
            events_y.emplace_back(rec[1], rec[3]);
        }
        // auto by_end = [](const Event &a, const Event &b) {
        //     if (a.second == b.second) return a.first < b.first;
        //     return a.second < b.second;
        // };
        sort(events_x.begin(), events_x.end());
        sort(events_y.begin(), events_y.end());
        auto x_sec_cnt = 0, y_sec_cnt = 0;
        auto x_end = events_x[0].second, y_end = events_y[0].second;
        for (size_t i = 1; i < n; i++) {
            if (events_x[i].first >= x_end) x_sec_cnt++;
            if (events_y[i].first >= y_end) y_sec_cnt++;
            if (x_sec_cnt == 2 or y_sec_cnt == 2) return true;
            x_end = max(x_end, events_x[i].second);
            y_end = max(y_end, events_y[i].second);
        }
        return false;
    }
};