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
    typedef pair<int, int> int_pair;
public:
    int maximumSwap(int num) {
        const auto origin = num;
        priority_queue<int_pair> pq;
        auto i = 1, ans = 0;
        auto target = 0, max_digit = 0;
        auto target_pos = 0, max_digit_pos = 0;
        for (; num; i *= 10, num /= 10) pq.emplace(num % 10, i);
        for (i /= 10; !pq.empty(); pq.pop(), i /= 10) {
            const auto [digit, pos] = pq.top();
            if (pos == i) continue;
            if (!max_digit) {
                max_digit_pos = pos;
                max_digit = digit;
                target_pos = i;
            } else if (digit == max_digit) max_digit_pos = pos;
            else if (pos == target_pos) {
                target = digit;
                break;
            }
        }
        return origin + (max_digit - target) * (target_pos - max_digit_pos);
    }
};