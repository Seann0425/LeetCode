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
public:
    string repeatLimitedString(string s, int repeat_limit) {
        /*
        1. 由於是要字典序最大，我們把字典序大的字元往前排不會使得答案更差
        2. 直到達到限制為止，我們都可以持續重複目前最佳的字元
        3. 到了限制之後，我們使用當前次大的字元
        4. 重複上述步驟直到沒有字元能放
        */
        array<int, 26> count{};
        for (const auto &c : s) count[c - 'a']++;
        string ans{};
        size_t current = 25;
        while (current < 26) {
            if (!count[current]) {
                current--;
                continue;
            }
            auto use = min(repeat_limit, count[current]);
            ans.append(use, current + 'a');
            count[current] -= use;
            if (!count[current]) continue;
            auto next_largest = current - 1;
            while (next_largest < 26 and !count[next_largest]) next_largest--;
            if (next_largest >= 26) break;
            ans.push_back(next_largest + 'a');
            count[next_largest]--;
        }
        return ans;
    }
};