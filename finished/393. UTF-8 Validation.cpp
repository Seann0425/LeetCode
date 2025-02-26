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
    bool is_trailing(int x) { return (x & 0b1100'0000) == 0b1000'0000; }
    int byte_count(int x) {
        return countl_one(static_cast<unsigned>(x) & 0b1111'1111 | 0xffff'ff00) - 24;
    }
    bool valid_trailing(const vector<int> &data, size_t i, size_t n) {
        for (size_t j = 1; j < n; ++j)
            if (i + j >= data.size() or !is_trailing(data[i + j])) return false;
        return true;
    }
public:
    bool validUtf8(vector<int> &data) {
        const auto n = data.size();
        for (auto i = 0uz; i < n; ++i) {
            const auto x = data[i];
            if (!(x & 0b1000'0000)) continue;
            const auto count = byte_count(x);
            if (count < 2 or count > 4) return false;
            if (!valid_trailing(data, i, count)) return false;
            i += count - 1;
        }
        return true;
    }
};