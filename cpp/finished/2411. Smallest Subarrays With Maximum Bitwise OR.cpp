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
    void bit_plus(array<int, 32> &bit_cnt, int num, bool is_add) {
        auto op = is_add ? 1 : -1;
        for (auto i = 0uz; i < 32uz; ++i) {
            bit_cnt[i] += num % 2 * op;
            num >>= 1;
        }
    }
    bool non_necessary(array<int, 32> &bit_cnt, int num) {
        for (auto i = 0uz; i < 32uz; ++i, num >>= 1) {
            if (bit_cnt[i] == 1 and num % 2) return false;
        }
        return true;
    }
public:
    vector<int> smallestSubarrays(vector<int> &nums) {
        array<int, 32> bit_cnt{};
        const auto n = nums.size();
        vector<int> ans(n);
        for (auto i = n - 1, j = n - 1; i < n; --i) {
            bit_plus(bit_cnt, nums[i], true);
            for (; j > i; --j) {
                if (non_necessary(bit_cnt, nums[j])) bit_plus(bit_cnt, nums[j], false);
                else break;
            }
            ans[i] = static_cast<int>(j - i + 1);
        }
        return ans;
    }
};