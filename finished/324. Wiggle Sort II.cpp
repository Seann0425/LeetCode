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
    void wiggleSort(vector<int> &nums) {
        array<int, 5005> cnt{};
        for (const auto &i : nums) cnt[i]++;
        const auto n = nums.size();
        auto i = 0uz, j = 0uz;
        for (i = n - 1 - !(n % 2); i < n; i -= 2) {
            while (!cnt[j]) j++;
            nums[i] = j;
            cnt[j]--;
        }
        for (i = 1uz, j = cnt.size() - 1; i < n; i += 2) {
            while (!cnt[j]) j--;
            nums[i] = j;
            cnt[j]--;
        }
    }
};
