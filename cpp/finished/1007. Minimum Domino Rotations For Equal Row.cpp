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
    int minDominoRotations(vector<int> &tops, vector<int> &bottoms) {
        const auto n = tops.size();
        array<int, 7> top_count{}, bottom_count{}, same_count{};
        for (auto i = 0uz; i < n; i++) {
            top_count[tops[i]]++;
            bottom_count[bottoms[i]]++;
            if (tops[i] == bottoms[i]) same_count[tops[i]]++;
        }
        for (auto i = 1uz; i < 7uz; i++) {
            if (top_count[i] + bottom_count[i] - same_count[i] == n)
                return n - max(top_count[i], bottom_count[i]);
        }
        return -1;
    }
};