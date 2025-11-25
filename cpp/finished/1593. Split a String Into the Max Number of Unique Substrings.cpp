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
    unordered_set<string_view> unique;
public:
    int maxUniqueSplit(string_view s, int count = 0, int best = 0) {
        if (count + static_cast<int>(s.size()) <= best) return best;
        if (s.empty()) return best = max(best, count);

        for (size_t i = 1; i <= s.size(); i++) {
            auto left = s.substr(0, i), r = s.substr(i);
            if (!unique.count(left)) {
                unique.insert(left);
                best = maxUniqueSplit(r, count + 1, best);
                unique.erase(left);
            }
        }
        return best;
    }
};

// class Solution {
//     int ans{};
//     unordered_set<string> unique;
//     void backtracking(string &s, size_t idx, string last) {
//         if (idx == s.size()) {
//             ans = max(ans, (unique.count(last) ? 0 : static_cast<int>(unique.size())));
//             return;
//         }
//         backtracking(s, idx + 1, last + s[idx]);
//         if (!unique.count(last)) {
//             unique.insert(last);
//             backtracking(s, idx + 1, ""s + s[idx]);
//             unique.erase(last);
//         }
//     }
// public:
//     int maxUniqueSplit(string s) {
//         backtracking(s, 0UZ, ""s);
//         return ans;
//     }
// };