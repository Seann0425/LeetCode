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
    bool canChange(string start, string target) {
        // problem guarantees that the length of start and targer are the same
        const auto n = start.size();
        auto wait_src_L = 0, wait_dst_R = 0;
        for (const auto &[src, dst] : views::zip(start, target)) {
            if (src == 'R') {
                if (wait_src_L) return false;
                wait_dst_R++;
            }
            if (dst == 'L') {
                if (wait_dst_R) return false;
                wait_src_L++;
            }
            if (src == 'L' and wait_src_L-- == 0) return false;
            if (dst == 'R' and wait_dst_R-- == 0) return false;
        }
        return !wait_src_L and !wait_dst_R;
    }
};