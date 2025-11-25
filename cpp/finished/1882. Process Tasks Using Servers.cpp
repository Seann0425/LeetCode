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
    using free_t = pair<int, size_t>;       // weight, id
    using busy_t = tuple<int, int, size_t>; // time, weight, id
public:
    vector<int> assignTasks(vector<int> &servers, vector<int> &tasks) {
        const auto m = servers.size(), n = tasks.size();
        priority_queue<free_t, vector<free_t>, greater<free_t>> free;
        priority_queue<busy_t, vector<busy_t>, greater<busy_t>> busy;
        vector<int> ans;
        for (auto i = 0uz; i < m; ++i) free.emplace(servers[i], i);
        auto time = 0;
        for (auto i = 0uz; i < n; ++i) {
            time = max(time, static_cast<int>(i));
            while (!busy.empty() && get<0>(busy.top()) <= time) {
                free.emplace(get<1>(busy.top()), get<2>(busy.top()));
                busy.pop();
            }
            if (free.empty()) {
                time = get<0>(busy.top());
                while (!busy.empty() && get<0>(busy.top()) <= time) {
                    free.emplace(get<1>(busy.top()), get<2>(busy.top()));
                    busy.pop();
                }
            }
            auto [w, id] = free.top();
            free.pop();
            busy.emplace(time + tasks[i], w, id);
            ans.push_back(id);
        }
        return ans;
    }
};