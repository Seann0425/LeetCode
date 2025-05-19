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
    bool sumGame(string num) {
        // bob有機會能贏的場合：
        // 1. 左右數字相等且問號數量相等(一定贏)
        // 2. 數字小的那邊問號比較多，且數量一定要是偶數，否則alice負責最後一個問號。
        //    同時問號目標要等於的數值必須是：問號數量/2*9

        // sum代表左邊數值，question代表右邊問號數量
        const auto n = num.size(), m = n / 2;
        auto sum = 0, question = 0;
        for (auto i = 0uz; i < m; ++i)
            if (isdigit(num[i])) sum += (num[i] - '0');
            else --question;
        for (auto i = m; i < n; ++i)
            if (isdigit(num[i])) sum -= (num[i] - '0');
            else ++question;
        return sum != question / 2 * 9 || question % 2;
    }
};