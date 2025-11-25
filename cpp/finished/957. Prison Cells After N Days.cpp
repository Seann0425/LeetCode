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

#pragma GCC optimize("O3", "unroll-loops")
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

static const auto InitialOptimization = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    return 0;
}();

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        for (n = (n - 1) % 14 + 1; n > 0; --n) {
            vector<int> next_cells(8, 0);
            for (auto i = 1uz; i < 7uz; ++i) next_cells[i] = cells[i - 1] == cells[i + 1];
            swap(cells, next_cells);
        }
        return cells;
    }
};

class Solution {
public:
    vector<int> prisonAfterNDays(vector<int> &cells, int n) {
        vector<int> next(8, 0);
        vector<vector<int>> seen{};
        for (auto i = 0; i < n; ++i) {
            for (auto j = 1; j < 7; ++j) next[j] = cells[j - 1] == cells[j + 1];
            if (!seen.empty() and seen.front() == next) return seen[(n - 1 - i) % i];
            else seen.push_back(next);
            cells = next;
        }
        return cells;
    }
};