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

class MyCalendarTwo {
    multimap<int, int> calendar, overlap;
public:
    MyCalendarTwo() {}

    bool book(int start, int end) {
        auto triple = overlap.upper_bound(start);
        if (!(triple == overlap.end() or triple->second >= end)) return false;

        for (const auto &event : calendar) {
            auto overlap_left = max(start, event.second);
            auto overlap_right = min(end, event.first);
            if (overlap_left >= overlap_right) continue;
            overlap.emplace(overlap_right, overlap_left);
        }
        calendar.emplace(end, start);
        return true;
    }
};
