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
public:
    int minCost(string colors, vector<int> &needed_time) {
        const auto n = colors.size();
        auto ans = 0, prev_max = needed_time.front();
        for (auto i = 1uz; i < n; i++) {
            if (colors[i] != colors[i - 1]) prev_max = 0;
            ans += min(prev_max, needed_time[i]);
            prev_max = max(prev_max, needed_time[i]);
        }
        return ans;
    }
};

// class Solution {
//     static constexpr int inf = 1e9 + 7;
// public:
//     int minCost(string colors, vector<int> &needed_time) {
//         const auto n = colors.size();
//         array<int, 27> last{}; // last[26] for empty
//         last.fill(inf);
//         last[26] = 0;
//         for (auto i = 0uz; i < n; i++) {
//             auto best = inf;
//             for (auto j = 0uz; j < 27uz; j++) {
//                 if (colors[i] - 'a' == j) continue;
//                 best = min(best, last[j]);
//                 last[j] = min(last[j] + needed_time[i], inf);
//             }
//             last[colors[i] - 'a'] = min(best, last[colors[i] - 'a'] + needed_time[i]);
//         }
//         return *min_element(last.begin(), last.end());
//     }
// };