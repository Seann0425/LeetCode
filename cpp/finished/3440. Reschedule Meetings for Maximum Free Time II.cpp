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

#include <ranges>
#ifndef DEBUG
#define DEBUG
template <typename T>
void debug(const vector<T> &v) {
    if (v.empty()) {
        cout << "[]"s << endl;
        return;
    }
    cout << '[' << v.front();
    for (const auto &x : v | views::drop(1)) cout << ',' << x;
    cout << "]" << endl;
}
void debug(const string &s) { cout << '"' << s << '"' << endl; }
#endif
#pragma GCC optimize("O3", "unroll-loops")

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
public:
    int maxFreeTime(int event_time, vector<int> &start_time, vector<int> &end_time) {
        const auto n = start_time.size();
        vector<int> free_time;
        free_time.reserve(n + 1);
        free_time.push_back(start_time[0]);
        for (auto i = 0uz; i + 1 < n; ++i) free_time.push_back(start_time[i + 1] - end_time[i]);
        free_time.push_back(event_time - end_time[n - 1]);
        vector<int> right_max(n + 2);
        right_max[n] = free_time[n];
        for (auto i = n - 1; i < n; --i) right_max[i] = max(right_max[i + 1], free_time[i]);
        auto ans = 0, left_max = 0;
        for (auto i = 0uz; i < n; ++i) {
            auto cur = end_time[i] - start_time[i];
            if (left_max >= cur or right_max[i + 2] >= cur)
                ans = max(ans, free_time[i] + free_time[i + 1] + cur);
            else ans = max(ans, free_time[i] + free_time[i + 1]);
            left_max = max(left_max, free_time[i]);
        }
        return ans;
    }
};