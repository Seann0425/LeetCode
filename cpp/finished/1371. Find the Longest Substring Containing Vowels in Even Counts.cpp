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
    array<char, 5> vowels{'a', 'e', 'i', 'o', 'u'};
public:
    int findTheLongestSubstring(string s) {
        const auto n = s.size();
        vector<vector<bool>> is_vowels(5, vector<bool>(n, false));
        vector<int> combinition(n, 0);

        for (size_t i = 0; i < n; i++) {
            for (size_t v = 0; v < 5; v++) {
                if (s[i] == vowels[v]) is_vowels[v][i] = true;
                if (i) is_vowels[v][i] = (is_vowels[v][i] != is_vowels[v][i - 1]);
                if (is_vowels[v][i]) combinition[i] += (1 << v);
            }
        }

        int ans = 0;
        unordered_map<int, size_t> first_occur;
        first_occur.emplace(0, numeric_limits<size_t>::max());
        for (size_t i = 0; i < n; i++) {
            if (!first_occur.count(combinition[i])) {
                first_occur.emplace(combinition[i], i);
                continue;
            }
            ans = max(ans, static_cast<int>(i - first_occur[combinition[i]]));
        }
        return ans;
    }
};