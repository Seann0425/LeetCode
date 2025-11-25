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
    vector<int> advantageCount(vector<int> &nums1, vector<int> &nums2) {
        const auto n = nums1.size();
        vector<int> index1(n), index2(n);
        iota(index1.begin(), index1.end(), 0);
        iota(index2.begin(), index2.end(), 0);
        sort(index1.begin(), index1.end(),
             [&](const int i, const int j) { return nums1[i] < nums1[j]; });
        sort(index2.begin(), index2.end(),
             [&](const int i, const int j) { return nums2[i] < nums2[j]; });
        vector<int> ans(n);
        for (auto i = 0uz, j = 0uz, k = n - 1; i < n; i++) {
            if (nums1[index1[i]] > nums2[index2[j]]) ans[index2[j++]] = nums1[index1[i]];
            else ans[index2[k--]] = nums1[index1[i]];
        }
        return ans;
    }
};