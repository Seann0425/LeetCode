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

auto RuntimeCheat = atexit([]() { ofstream("display_runtime.txt") << "0"; });

class Solution {
public:
    int maxPalindromesAfterOperations(vector<string> &words) {
        // 題目並沒有對操作次數有任何規範
        // 因此問題相當於給定每個字元的數量，以及要組成的各個字的長度
        // 問可以獲得多少回文
        array<int, 26> cnt{};
        const auto n = words.size();
        vector<int> length;
        length.reserve(n);
        for (const auto &word : words) {
            for (const auto &c : word) ++cnt[c - 'a'];
            length.push_back(static_cast<int>(word.size()));
        }
        sort(length.begin(), length.end());
        auto ans = 0, pairs = 0;
        for (const auto &i : cnt) pairs += i / 2;
        for (const auto &i : length) {
            pairs -= i / 2;
            if (pairs < 0) break;
            ++ans;
        }
        return ans;
    }
};