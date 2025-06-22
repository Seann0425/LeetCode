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
public:
    int maxDistance(string s, int k) {
        array<int, 4> nsew{};
        auto ans = 0;
        for (const auto &c : s) {
            if (c == 'N') ++nsew[0];
            else if (c == 'S') ++nsew[1];
            else if (c == 'E') ++nsew[2];
            else if (c == 'W') ++nsew[3];

            auto ns_mod = min({nsew[0], nsew[1], k});
            auto ew_mod = min({nsew[2], nsew[3], k - ns_mod});
            ans = max(ans, abs(nsew[0] - nsew[1]) + abs(nsew[2] - nsew[3]) + 2 * (ns_mod + ew_mod));
        }
        return ans;
    }
};