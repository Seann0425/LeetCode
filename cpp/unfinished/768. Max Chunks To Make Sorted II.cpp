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
    int maxChunksToSorted(vector<int> &arr) {
        const auto n = arr.size();
        auto ans = 0, maximum = numeric_limits<int>::min(), minimum = numeric_limits<int>::max();
        vector<int> left_max(n), right_min(n);
        for (auto i = 0; i < n; i++) left_max[i] = maximum = max(maximum, arr[i]);
        for (auto i = n - 1; i < n; i--) right_min[i] = minimum = min(minimum, arr[i]);
        for (auto i = 0uz; i < n; i++)
            if (i == n - 1 or left_max[i] <= right_min[i + 1]) ans++;
        return ans;
    }
};