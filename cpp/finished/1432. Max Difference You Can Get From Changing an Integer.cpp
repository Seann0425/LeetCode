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

// #pragma GCC optimize("O3", "unroll-loops")
// static const auto InitialOptimization = [](){
//     ios_base::sync_with_stdio(false);
//     cin.tie(0);
//     cout.tie(0);
//     return 0;
// }();

#include <ranges>
class Solution {
    // find the first digit that is not 9 and change it to 9
    auto to_max(int num) {
        auto s = to_string(num);
        auto x = '#';
        for (auto &c : s) {
            if (x == '#' and c != '9') x = c, c = '9';
            else if (x != '#' and c == x) c = '9';
        }
        return stoi(s);
    }
    // change the first digit to 1 if it is not 1
    // otherwise, find the first digit that is not 0 and change it to 0
    auto to_min(int num) {
        auto s = to_string(num);
        auto x = '#', y = '#';
        if (s.front() == '1') {
            for (auto &c : s | views::drop(1)) {
                if (x == '#' and c != '1' and c != '0') x = c, c = '0';
                else if (x != '#' and c == x) c = '0';
            }
        } else {
            for (auto &c : s) {
                if (x == '#' and c != '1') x = c, c = '1';
                else if (x != '#' and c == x) c = '1';
            }
        }
        return stoi(s);
    }
public:
    int maxDiff(int num) { return to_max(num) - to_min(num); }
};