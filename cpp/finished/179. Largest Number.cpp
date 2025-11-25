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
    string largestNumber(vector<int> &nums) {
        unordered_map<int, string> trans;
        for (const auto &i : nums) trans.emplace(i, to_string(i));
        sort(nums.begin(), nums.end(), [&](const int &a, const int &b) {
            const auto n = trans[a].size(), m = trans[b].size();
            size_t i = 0, j = 0;
            for (; i < n + m; i++, j++) {
                if (trans[a][i % n] > trans[b][j % m]) return true;
                else if (trans[a][i % n] < trans[b][j % m]) return false;
            }
            return false;
        });
        string ans;
        for (const auto &i : nums) {
            if (!i and ans.empty()) continue;
            ans += trans[i];
        }
        return ans.empty() ? "0" : ans;
    }
};