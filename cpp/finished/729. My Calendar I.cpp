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

class MyCalendar {
    set<pair<int, int>> calendar;
    static bool cmp(const pair<int, int> &p, const int &s) { return p.first < s; }
public:
    MyCalendar() {}

    bool book(int start, int end) {
        if (calendar.empty()) {
            calendar.emplace(start, end);
            return true;
        }
        if (start < calendar.begin()->first) {
            if (end <= calendar.begin()->first) {
                calendar.emplace(start, end);
                return true;
            }
            return false;
        }
        if (start > prev(calendar.end())->first) {
            if (start >= prev(calendar.end())->second) {
                calendar.emplace(start, end);
                return true;
            }
            return false;
        }
        const auto const pos = lower_bound(calendar.begin(), calendar.end(), start, cmp);
        const auto &left = pos == calendar.begin() ? *pos : *prev(pos);
        const auto &right = *pos;
        if (start < left.second) return false;
        if (end > right.first) return false;
        calendar.emplace(start, end);
        return true;
    }
};