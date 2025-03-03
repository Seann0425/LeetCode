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
    vector<string> ans{};
    uint16_t alpha_limit = 1;
    void backtrack(const string &s, uint16_t bit_comb) {
        if (bit_comb == alpha_limit) return;
        string ans_str = ""s;
        auto original = bit_comb;
        for (const auto &c : s) {
            if (isalpha(c)) {
                if (bit_comb & 1) ans_str += tolower(c);
                else ans_str += toupper(c);
                bit_comb >>= 1;
            } else ans_str += c;
        }
        ans.push_back(ans_str);
        backtrack(s, original + 1);
    }
public:
    vector<string> letterCasePermutation(string s) {
        uint16_t bit_combination = 0;
        for (const auto &c : s)
            if (isalpha(c)) alpha_limit <<= 1;
        backtrack(s, bit_combination);
        return ans;
    }
};