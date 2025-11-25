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
    int takeCharacters(string s, int k) {
        array<int, 3> cnt{};
        for (const auto &c : s) cnt[c - 'a']++;
        if (any_of(cnt.begin(), cnt.end(), [k](int x) { return x < k; })) return -1;

        const auto n = s.size();
        auto ans = n;
        for (size_t l = 0, r = 0; l < n; cnt[s[l++] - 'a']++) {
            while (r < n && cnt[s[r] - 'a'] > k) cnt[s[r++] - 'a']--;
            ans = min(ans, n - r + l);
        }
        return static_cast<int>(ans);
    }
};