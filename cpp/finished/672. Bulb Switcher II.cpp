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
    // the first 3 bulbs can determine the rest
    // the second bulb indicates the even flip
    // the third bulb indicates the odd flip
    // the difference between the first bulb and the third bulb is the 3k+1 flip
    // so we only need to consider the first 3 bulbs
public:
    int flipLights(int n, int presses) {
        if (presses == 0) return 1;
        if (n == 1) return 2;
        if (n == 2) return min(4, 1 + 2 * presses);
        if (presses == 1) return 4;
        if (presses == 2) return 7;
        return 8;
    }
};

// class Solution {
//     static constexpr size_t max_n = 1005;
//     array<bitset<max_n>, 4> buttons{}; // 0: all, 1: even, 2: odd, 3: 3k+1
//     bitset<max_n> light;
//     void init_buttons(size_t n) {
//         for (auto i = 1uz; i <= n; ++i) {
//             buttons[0].set(i);
//             if (i & 1) buttons[2].set(i);
//             else buttons[1].set(i);
//             if (i % 3 == 1) buttons[3].set(i);
//         }
//     }
// public:
//     int flipLights(size_t n, int presses) {
//         light.set();
//         init_buttons(n);
//         unordered_set<bitset<max_n>> states;
//         states.insert(light);
//         for (auto i = 0; i < presses; ++i) {
//             unordered_set<bitset<max_n>> next_states;
//             for (const auto &state : states)
//                 for (const auto &button : buttons) next_states.insert(state ^ button);
//             states = std::move(next_states);
//         }
//         return static_cast<int>(states.size());
//     }
// };