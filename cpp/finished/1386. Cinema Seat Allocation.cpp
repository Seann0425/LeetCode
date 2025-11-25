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

class Solution {
    static constexpr bitset<10> left{0b0111100000}, middle{0b0001111000}, right{0b0000011110};
    auto eliminate(const bitset<10> &row) {
        if ((row & left) == left and (row & right) == right) return 0;
        if ((row & left) == left or (row & right) == right or (row & middle) == middle) return 1;
        return 2;
    }
public:
    int maxNumberOfFamilies(int n, vector<vector<int>> &reserved_seats) {
        sort(reserved_seats.begin(), reserved_seats.end());
        auto ans = 2 * n, cur_row = 0;
        bitset<10> row(0xfff);
        for (const auto &seat : reserved_seats) {
            if (seat[0] != cur_row) {
                ans -= eliminate(row);
                row.set();
                cur_row = seat[0];
            }
            row.reset(seat[1] - 1);
        }
        ans -= eliminate(row);
        return ans;
    }
};
