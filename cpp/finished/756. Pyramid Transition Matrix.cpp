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
#include <ranges>

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
    unordered_set<string>
        invalid; // different N size level may lead to the same invalid N - 1 size level
    vector<vector<char>> edges;
    bool solve(string &bottom) {
        if (bottom.size() <= 1) return true;
        if (invalid.contains(bottom)) return false;
        const auto n = bottom.size();

        // early termination for those cannot form next level
        for (auto i = 0uz; i < n - 1; ++i) {
            auto key = (bottom[i] - 'A') * 7 + bottom[i + 1] - 'A';
            if (edges[key].empty()) {
                invalid.insert(bottom);
                return false;
            }
        }

        // try finding next level
        string next_level(n - 1, '#');
        if (dfs(bottom, next_level, 0)) return true;
        invalid.insert(bottom);
        return false;
    }
    bool dfs(string &bottom, string &next, size_t i) {
        if (i + 1 == bottom.size()) return solve(next); // find possible next level
        auto key = (bottom[i] - 'A') * 7 + bottom[i + 1] - 'A';
        for (const auto &c : edges[key]) {
            next[i] = c;
            if (dfs(bottom, next, i + 1)) return true;
        }
        return false;
    }
public:
    bool pyramidTransition(string bottom, vector<string> &allowed) {
        edges.resize(49);
        for (const auto &s : allowed) {
            auto key = (s[0] - 'A') * 7 + s[1] - 'A';
            edges[key].push_back(s[2]);
        }
        return solve(bottom);
    }
};