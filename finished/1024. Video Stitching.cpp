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
    int videoStitching(vector<vector<int>> &clips, int time) {
        sort(clips.begin(), clips.end(), [](const auto &a, const auto &b) { return a[0] < b[0]; });
        for (const auto &v : clips) cout << v[0] << " " << v[1] << endl;
        auto cur = 0, ans = 0, max_end = 0;
        for (const auto &clip : clips) {
            if (clip[0] <= cur) {
                if (clip[1] >= time) return ans + 1;
                max_end = max(max_end, clip[1]);
            } else {
                cur = max_end;
                if (cur < clip[0]) return -1;
                ans++;
                if (clip[1] >= time) return ans + 1;
                max_end = max(max_end, clip[1]);
            }
        }
        return max_end >= time ? ans + 1 : -1;
    }
};