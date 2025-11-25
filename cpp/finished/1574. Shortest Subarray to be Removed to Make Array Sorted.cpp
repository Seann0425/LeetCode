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
    int findLengthOfShortestSubarray(vector<int> &arr) {
        const auto n = arr.size();
        size_t left_end = 0, right_start = n - 1;
        for (; left_end + 1 < n && arr[left_end] <= arr[left_end + 1]; left_end++);
        if (left_end == n - 1) return 0;
        for (; right_start > 0 && arr[right_start - 1] <= arr[right_start]; right_start--);

        auto ans = static_cast<int>(n);
        for (size_t i = left_end, end = n - 1; i < n; i--) {
            while (right_start <= end && arr[i] <= arr[end]) end--;
            ans = min(ans, static_cast<int>(end - i));
        }
        return min(ans, static_cast<int>(right_start));
    }
};