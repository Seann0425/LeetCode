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
    int minSwaps(vector<vector<int>> &grid) {
        const auto n = grid.size();
        vector<int> right_zeros(n);
        for (auto i = 0uz; i < n; i++) {
            auto count = 0;
            for (auto j = n - 1; j < n; j--)
                if (!grid[i][j]) count++;
                else break;
            right_zeros[i] = count;
        }
        auto ans = 0;
        for (auto i = 0uz; i < n; i++) {
            auto target = static_cast<int>(n - 1 - i); // greater equal
            if (right_zeros[i] >= target) continue;
            auto found = false;
            for (auto j = i + 1; j < n; j++) {
                if (right_zeros[j] < target) continue;
                found = true;
                ans += static_cast<int>(j - i);
                while (j > i) swap(right_zeros[j], right_zeros[j - 1]), j--;
                break;
            }
            if (!found) return -1;
        }
        return ans;
    }
};